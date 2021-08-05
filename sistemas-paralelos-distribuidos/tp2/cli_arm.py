import sys
import grpc
import arm_pb2 as st
import arm_pb2_grpc

def cli(server_host):
  channel = grpc.insecure_channel(server_host)
  stub = arm_pb2_grpc.ArmStub(channel)
  line = ['X']
  while (line[0] != 'T'):
    line = list(map(str, input().split(',')))
    
    if (line[0] == 'C'):
      rr = stub.Consulta(st.ConsultaReq(chave=int(line[1])))
      if len(rr.desc) > 0:
        print(rr.desc, rr.valor)
      else:
        print(rr.valor)

    elif (line[0] == 'I'):
      rr = stub.Insercao(st.InsercaoReq(chave=int(line[1]), desc=line[2], valor=int(line[3])))
      print(rr.valor)

  stub.Termina(st.Empty())

if __name__ == '__main__':
  cli(sys.argv[1])