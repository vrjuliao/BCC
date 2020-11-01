from router import Router
from main import get_system_arguments
import socket


def main():
  args = get_system_arguments()
  udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

  msg = input()
  udp.sendto(msg.encode(), (args['ipaddr'], 55151))

  response, source = udp.recvfrom(1024)
  print(response.decode('utf-8'))

if __name__ == '__main__':
  main()