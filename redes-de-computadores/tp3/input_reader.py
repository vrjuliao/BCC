import sys, fileinput

class InputReader:
  def __init__(self, router):
    self.__router = router

  def __get_command(self, strline):
    cmd = strline.split()
    if cmd[0] == 'add':
      return ('add', cmd[1], int(cmd[2]))
    elif cmd[0] == 'del':
      return ('del', cmd[1])
    elif (cmd[0]) == 'quit':
      raise KeyboardInterrupt()
    elif (cmd[0]) == 'trace':
      return('trace', cmd[1])
    else:
      return (strline)

  def __execute(self, command):
    command = command.rstrip()
    try:
      cmd_attributes = self.__get_command(command)
      action = cmd_attributes[0]
      if action == 'add':
        self.__router.new_address(cmd_attributes[1], cmd_attributes[2])
      elif action == 'del':
        self.__router.del_address(cmd_attributes[1])
      elif action == 'trace':
        self.__router.start_trace(cmd_attributes[1])
      else:
        print('Unsupported command "{strline}"'.
          format(strline=action))
    except Exception as err:
      print(err)

  def from_file(self, filename):
    for command in fileinput.input(files = filename): 
      self.__execute(command)

  def from_stdin(self):
    for command in sys.stdin: 
      self.__execute(command)