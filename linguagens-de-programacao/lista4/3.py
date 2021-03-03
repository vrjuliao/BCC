class Node:
  def __init__(self):
    self.n = 0
    self.e = ''

class Queue:
  def __init__(self):
    self.head = self.tail = Node()

  def add(self, txt):
    new_tail = Node()
    self.tail.n = new_tail
    self.tail.e = str(txt)
    self.tail = new_tail
    
  def remove(self):
    if self.isNotEmpty():
      txt = self.head.e
      self.head = self.head.n
      return txt

  def getSmaller(self):
    smaller = self.head.e
    current = self.head.n
    
    while current.n != 0:
      print(current.e)
      if smaller > current.e:
        smaller = current.e
      current = current.n
    return smaller

  def isNotEmpty(self):
    return (self.head.n != 0)