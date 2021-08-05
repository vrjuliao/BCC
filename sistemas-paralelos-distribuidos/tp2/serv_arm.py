import sys
import concurrent.futures as futures
import grpc
import arm_pb2 as st
import arm_pb2_grpc

class Arm(arm_pb2_grpc.ArmServicer):
  def __init__(self, server):
    self.__data = {}
    self.__server = server

  def Insercao(self, request, context):
    if request.chave not in self.__data:
      self.__data[request.chave] = (request.desc, request.valor)
      return  st.IntRet(valor=0)
    return  st.IntRet(valor=-1)

  def Consulta(self, request, context):
    if request.chave in self.__data:
      (loc_desc, loc_valor) = self.__data[request.chave]
      return  st.ConsultaRet(desc=loc_desc, valor=loc_valor)
    return  st.ConsultaRet(desc="", valor=0)
  
  def Termina(self, request, context):
    self.__server.stop(1)
    return st.IntRet(valor=0)


def serv(port):
  server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
  arm_pb2_grpc.add_ArmServicer_to_server(
      Arm(server), server)
  server.add_insecure_port('[::]:'+port)
  server.start()
  server.wait_for_termination()

if __name__ == '__main__':
  serv(sys.argv[1])