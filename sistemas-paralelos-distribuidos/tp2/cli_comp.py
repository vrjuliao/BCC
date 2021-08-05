import sys
import grpc
import comp_pb2 as st
import comp_pb2_grpc

def cli(server_host):
  channel = grpc.insecure_channel(server_host)
  stub = comp_pb2_grpc.CompStub(channel)
  line = ['X']
  while (line[0] != 'T'):
    line = list(map(str, input().split(',')))
    
    if (line[0] == 'C'):
      rr = stub.Consulta(st.CompConsultaReq(ch=int(line[1])))
      if len(rr.nome) > 0:
        print(rr.nome, rr.matr, rr.curso, rr.cred)
      else:
        print(-1)
  stub.Termina(st.CompEmpty())
  

if __name__ == '__main__':
  cli(sys.argv[1])