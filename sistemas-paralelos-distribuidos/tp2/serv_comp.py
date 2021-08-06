import sys
import concurrent.futures as futures
import grpc
import arm_pb2 as arm_pb2
import comp_pb2 as comp_stub
import comp_pb2_grpc
import arm_pb2_grpc

# Classe de implementação do servidor de consulta RCP
class Comp(comp_pb2_grpc.CompServicer):
  def __init__(self, server, siga_host, matricula_host):
    self.__server = server
    # inicializacao do lado cliente dos servico de armazenamento
    # para o servidor SIGA e MATRICULA
    matricula_channel = grpc.insecure_channel(matricula_host)
    siga_channel = grpc.insecure_channel(siga_host)
    self.__matricula_stub = arm_pb2_grpc.ArmStub(matricula_channel)
    self.__siga_stub = arm_pb2_grpc.ArmStub(siga_channel)

  def Consulta(self, request, context):
    loc_nome = ""
    loc_matr = 0
    loc_curso = ""
    loc_cred = 0
    # consulta ao servidor SIGA
    ret_siga = self.__siga_stub.Consulta(arm_pb2.ConsultaReq(chave=request.ch))
    if(len(ret_siga.desc) > 0):
      # preenchimento dos valores de retorno de SIGA quando estes sao validos
      loc_nome = ret_siga.desc
      loc_matr = ret_siga.valor
      
      # consulta ao servidor MATRICULA
      ret_matricula = self.__matricula_stub.Consulta(arm_pb2.ConsultaReq(chave=loc_matr))
      
      # preenchimento dos valores de retorno de MATRICULA de acordo
      # com o que fora solicitado
      if(len(ret_matricula.desc) == 0):
        loc_curso = "N/M"
      else:
        loc_curso = ret_matricula.desc
        loc_cred = ret_matricula.valor
    return comp_stub.CompConsultaRet(nome=loc_nome, matr=loc_matr, curso=loc_curso, cred=loc_cred)
  
  def Termina(self, request, context):
    # expede o termino da execucao dos servidores SIGA e MATRICULA
    # por simplicidade de construcao, optou-se por fazê-lo de forma sequencial
    ret_siga = self.__siga_stub.Termina(arm_pb2.Empty())
    ret_matricula = self.__matricula_stub.Termina(arm_pb2.Empty())
    
    # uma vez que e' necesario interromper o servidor, adiciona-se um dalay
    # de 1 segundo, para que haja tempo sucifiente de responder ao cliente
    self.__server.stop(1)
    return comp_stub.CompIntRet(valor=(ret_siga.valor + ret_matricula.valor))

# disparo do servidor
def serv(args):
  # optou-se por possibiliar que o servidor tenha um pool com 10 threads
  server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
  comp_pb2_grpc.add_CompServicer_to_server(
      Comp(server, args[1], args[2]), server)
  # alocacao dos recursos de rede
  server.add_insecure_port('[::]:'+args[0])
  server.start()

  # a thread principal sera bloqueada ate que o Comp.Termina() seja executado
  server.wait_for_termination()

if __name__ == '__main__':
  serv(sys.argv[1:])