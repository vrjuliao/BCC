NULL = -1
# The  null  link
class  HeapManager:
  """ Implements a very  simple  heap  manager."""
  def  __init__(self , initialMemory):
    """ Constructor. Parameter  initialMemory  is the  array ofdata  that we will
    use to  represent  the  memory."""
    self.memory = initialMemory
    self.memory [0] = self.memory.__len__ ()
    self.memory [1] = NULL
    self.freeStart = 0
    
  def allocate(self , requestSize):
    """ Allocates a block of data , and  return  its  address. The parameter
    requestSize  is the  amount  of space  that  must be  allocaed. """
    size = requestSize + 1
    # Do first-fit  search: linear  search  of the  free  list  forthe  first  block
    # of  sufficient  size.
    p = self.freeStart 
    lag = NULL
    while p != NULL  and  self.memory[p] < size:
      lag = p
      p = self.memory[p + 1]

    if p == NULL:
      raise  MemoryError ()

    nextFree = self.memory[p + 1]
    unused = self.memory[p] - size
    
    if  unused  > 1:
      nextFree = p + size
      self.memory[nextFree] = unused
      self.memory[nextFree + 1] = self.memory[p + 1]
      self.memory[p] = size
    
    if lag == NULL:
      self.freeStart = nextFree
    else:
      self.memory[lag + 1] = nextFree
    
    return p + 1

  def deallocate(self, address):
    faddr = address-1
    
    if self.freeStart == NULL:
      self.memory[address] = NULL
      self.freeStart = faddr
    elif self.freeStart > faddr:
      self.memory[address] = self.freeStart
      self.freeStart = faddr
    else:
      p = self.freeStart
      lag = NULL
      while p != NULL and p < faddr:
        lag = p
        p = self.memory[p + 1]

      if(lag != NULL):
        self.memory[lag+1] = faddr
        self.memory[address] = p

def test():
  h = HeapManager ([0 for x in range(0, 10)])
  a = h.allocate (2)
  print("a = ", a, ", Memory = ", h.memory, h.freeStart)  
  b = h.allocate (2)
  print("b = ", b, ", Memory = ", h.memory, h.freeStart)

test()