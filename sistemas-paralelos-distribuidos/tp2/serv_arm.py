import sys
import concurrent.futures as futures
import grpc
import arm_pb2 as st
import arm_pb2_grpc
import threading

done = threading.Event()

# Classe de implementação do servidor de armazenamento RCP
class Arm(arm_pb2_grpc.ArmServicer):
  def __init__(self):
    # dicionario de armazenamento
    self.__data = {}

  def Insercao(self, request, context):
    # caso a chave nao exista no dicionario, entao ela e' inserida
    if request.chave not in self.__data:
      self.__data[request.chave] = (request.desc, request.valor)
      return  st.IntRet(valor=0)
    
    # chave já existente no dicionario
    return  st.IntRet(valor=-1)

  def Consulta(self, request, context):
    # ao encontrar determinada chave no dicionario, retorna os respectivos dados
    if request.chave in self.__data:
      (loc_desc, loc_valor) = self.__data[request.chave]
      return  st.ConsultaRet(desc=loc_desc, valor=loc_valor)
    
    # Como os dados nao estao no dicionario, retorna o valor vazio
    return  st.ConsultaRet(desc="", valor=0)
  

  def Termina(self, request, context):
    # uma vez que e' necesario interromper o servidor, adiciona-se um dalay
    # de 1 segundo, para que haja tempo sucifiente de responder ao cliente
    done.set()
    return st.IntRet(valor=0)

# disparo do servidor
def serv(port):
  # optou-se por possibiliar que o servidor tenha um pool com 10 threads
  server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
  arm_pb2_grpc.add_ArmServicer_to_server(
      Arm(), server)
  
  # alocacao dos recursos de rede
  server.add_insecure_port('[::]:'+port)
  server.start()

  # a thread principal sera bloqueada ate que o Arm.Termina() seja executado
  done.wait()
  server.stop(1)

if __name__ == '__main__':
  serv(sys.argv[1])