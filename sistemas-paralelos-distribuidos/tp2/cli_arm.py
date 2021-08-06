import sys
import grpc
import arm_pb2 as st
import arm_pb2_grpc

# Executa a rotina do cliente do servidor de armazenamento
def cli(server_host):
  # cria o canal de comunicação com o servidor
  channel = grpc.insecure_channel(server_host)
  # Define o stub de acordo com o canal do servidor
  stub = arm_pb2_grpc.ArmStub(channel)
  
  # inicializacao da entrada com um valor que será ignorado
  line = ['X']

  while (line[0] != 'T'):
    # supressao da mensagem de erro de fim de arquivo
    try:
      # parsing da entrada
      line = list(map(str, input().split(',')))
    except EOFError:
      return
    
    if (line[0] == 'C'):
      # Consulta o servidor. line[1] contem a chave a ser consultada
      rr = stub.Consulta(st.ConsultaReq(chave=int(line[1])))
      
      # tratamendo da saida
      if len(rr.desc) > 0:
        print(rr.desc, rr.valor)
      else:
        print(rr.valor)

    elif (line[0] == 'I'):
      # Insercao de um novo elemento
      rr = stub.Insercao(st.InsercaoReq(chave=int(line[1]), desc=line[2], valor=int(line[3])))
      print(rr.valor)

  # Nete ponto line[0] == 'T', logo o servidor foi encerrado e o cliente
  # tambem sera
  stub.Termina(st.Empty())

if __name__ == '__main__':
  cli(sys.argv[1])