import sys
import grpc
import comp_pb2 as st
import comp_pb2_grpc

# Executa a rotina do cliente do servidor de consulta
def cli(server_host):
  # cria o canal de comunicação com o servidor
  channel = grpc.insecure_channel(server_host)
  # Define o stub de acordo com o canal do servidor
  stub = comp_pb2_grpc.CompStub(channel)

  # line: variavel que armazenara os dados lidos da entrada padrao
  # line e' inicializada com um valor que sera' ingorado
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
      rr = stub.Consulta(st.CompConsultaReq(ch=int(line[1])))
      # tratamendo da saida
      if len(rr.nome) > 0:
        print(rr.nome, rr.matr, rr.curso, rr.cred)
      else:
        print(-1)

  # Nete ponto line[0] == 'T', logo o servidor foi encerrado e o cliente
  # tambem sera
  stub.Termina(st.CompEmpty())
  

if __name__ == '__main__':
  cli(sys.argv[1])