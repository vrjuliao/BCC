import sys
import argparse
from input_reader import InputReader
from router import Router

def main():
  args = get_system_arguments()
  print(args)
  router = Router(args['ipaddr'], args['period'])
  reader = InputReader(router)

  router.start()

  if args['startup'] is not None:
    reader.from_file(args['startup'])

  try:
    reader.from_stdin()
  except KeyboardInterrupt:
    pass
  
  router.terminate()

def get_system_arguments():
  parser = argparse.ArgumentParser()

  ipaddr_group = parser.add_mutually_exclusive_group(required=True)
  ipaddr_group.add_argument('IPADDR', nargs='?',
    help='IP address')
  ipaddr_group.add_argument('--addr', metavar='IPADDR',
    help='Specify the IP address')

  period_group = parser.add_mutually_exclusive_group(required=True)
  period_group.add_argument('PERIOD', nargs='?', type=int,
    help='Range of updated messages sent to neighbor routers')
  period_group.add_argument('--update-period', metavar='PERIOD',
    help='Specify PERIOD', type=int)

  startup_group = parser.add_mutually_exclusive_group()
  startup_group.add_argument('STARTUP', nargs='?',
    help='Startup file')
  startup_group.add_argument('--startup-commands', metavar='STARTUP',
    help='Specify STARTUP')

  
  args = parser.parse_args()
  arguments = {
    'startup': args.STARTUP,
    'ipaddr': args.IPADDR,
    'period': args.PERIOD
  }

  if args.startup_commands is not None:
    arguments['startup'] = args.startup_commands
  
  if args.update_period is not None:
    arguments['period'] = args.update_period

  if args.addr is not None:
    arguments['ipaddr'] = args.addr

  return arguments

if __name__ == '__main__':
  main()