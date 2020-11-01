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
      sys.exit()
    else:
      raise Exception('Unsupported command "{strline}"'.
        format(strline=strline))

  def __execute(self, command):
    command = command.rstrip()
    try:
      cmd_attributes = self.__get_command(command)
      if cmd_attributes[0] == 'add':
        self.__router.new_address(cmd_attributes[1], cmd_attributes[2])
      else:
        self.__router.del_address(cmd_attributes[1])
    except Exception as err:
      print(err)

  def from_file(self, filename):
    for command in fileinput.input(files = filename): 
      self.__execute(command)

  def from_stdin(self):
    for command in sys.stdin: 
      self.__execute(command)