class Node:
  def __init__(self):
    self.n = 0
    self.e = ''

class Stack:
  def __init__(self):
    self.top = Node()
  
  def add(self, txt):
    node = Node()
    node.e = str(txt)
    node.n = self.top
    self.top = node
  
  def remove(self):
    if self.isNotEmpty():
      txt = self.top.e
      self.top = self.top.n
      return txt

  def isNotEmpty(self):
    return (self.top.n != 0)