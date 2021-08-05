import sys
import concurrent.futures as futures
import grpc
import arm_pb2 as arm_pb2
import comp_pb2 as comp_stub
import comp_pb2_grpc
import arm_pb2_grpc

class Comp(comp_pb2_grpc.CompServicer):
  def __init__(self, server, siga_host, matricula_host):
    self.__server = server
    matricula_channel = grpc.insecure_channel(matricula_host)
    siga_channel = grpc.insecure_channel(siga_host)
    self.__matricula_stub = arm_pb2_grpc.ArmStub(matricula_channel)
    self.__siga_stub = arm_pb2_grpc.ArmStub(siga_channel)

  def Consulta(self, request, context):
    ret_siga = self.__siga_stub.Consulta(arm_pb2.ConsultaReq(chave=request.ch))
    loc_nome = ""
    loc_matr = 0
    loc_curso = ""
    loc_cred = 0
    if(len(ret_siga.desc) > 0):
      loc_nome = ret_siga.desc
      loc_matr = ret_siga.valor
      
      ret_matricula = self.__matricula_stub.Consulta(arm_pb2.ConsultaReq(chave=loc_matr))
      if(len(ret_matricula.desc) == 0):
        loc_curso = "N/M"
      else:
        loc_curso = ret_matricula.desc
        loc_cred = ret_matricula.valor
    return comp_stub.CompConsultaRet(nome=loc_nome, matr=loc_matr, curso=loc_curso, cred=loc_cred)
  
  def Termina(self, request, context):
    ret_siga = self.__siga_stub.Termina(arm_pb2.Empty())
    ret_matricula = self.__matricula_stub.Termina(arm_pb2.Empty())
    self.__server.stop(1)
    return comp_stub.CompIntRet(valor=(ret_siga.valor + ret_matricula.valor))


def serv(args):
  server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
  comp_pb2_grpc.add_CompServicer_to_server(
      Comp(server, args[1], args[2]), server)
  server.add_insecure_port('[::]:'+args[0])
  server.start()
  server.wait_for_termination()

if __name__ == '__main__':
  serv(sys.argv[1:])