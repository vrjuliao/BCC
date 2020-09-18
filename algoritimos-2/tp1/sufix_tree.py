import pdb

class Node:
  def __init__(self, left, right, end_of_string):
    self.__childrens = []
    self.__sufix = (left, right)
    self.__end_of_string = end_of_string

  def find_children(self, text, left, right):
    for index in range(len(self.__childrens)):
      child = self.__childrens[index]
      if (text[child.sufix[0]] == text[left]):
        return self.__childrens[index], index
    return None, -1

  def set_children(self, node, index):
    self.__childrens[index] = node

  def new_children(self, node):
    self.__childrens.append(node)

  @property
  def sufix(self):
    return self.__sufix

  @sufix.setter
  def sufix(self, sufix):
    self.__sufix = sufix

  @property
  def end_of_string(self):
    return self.__end_of_string

  @end_of_string.setter
  def end_of_string(self, end_of_string):
    self.__end_of_string = end_of_string

  @property
  def childrens(self):
    return self.__childrens


class SufixTree:
  def __init__(self, text):
    self.__text = text
    self.__root = Node(-1, -1, False)
    self.__create_tree(text)

  def __create_tree(self, text):
    right, left = 0, 0
    # pdb.set_trace()
    for i in range(len(text)-1, -1, -1):
      current_node = self.__root
      left = i
      right = len(text)-1
      child, child_index = current_node.find_children(text, left, right)
      # create a new node with indexes being the difference between current_node.left
      create_new_node = True
      while(child is not None):
        new_substr, new_child_substr = self.__difference_sufixes(child.sufix[0],
          child.sufix[1], left, right)

        # changing the substrings values in the nodes
        new_sufix_len = new_child_substr[1] - new_child_substr[0]
        child_sufix_len = child.sufix[1] - child.sufix[0]
        if(new_sufix_len == child_sufix_len):
          child.sufix = new_child_substr
          current_node = child
          left, right = new_substr
          child, child_index = current_node.find_children(text, left, right)
          # 1 - reestart loop changing left and right values, and getting a new 
          #     child node
        else:
          # 1 - create a new_child = child
          # 2 - set the sufix of new_child = the difference of the current sufix
          #     and t
          new_child = Node(new_child_substr[0], new_child_substr[1], False)
          child.sufix = (child.sufix[0]+new_sufix_len+1, child.sufix[1])
          new_child.new_children(Node(new_substr[0], new_substr[1], True))
          new_child.new_children(child)
          # 3 - the old child will be a children of new_child
          current_node.set_children(new_child, child_index)
          create_new_node = False
          break

      if create_new_node:
        current_node.new_children(Node(left, right, True))

  def __difference_sufixes(self, nleft, nright, mleft, mright):
    new_left = mleft
    
    for i in range(nleft, nright+1, 1):

      if(self.__text[i] != self.__text[mleft]):
        break
        # return (mleft, mright), (new_left, mleft-1)
      else:
        mleft += 1
    return (mleft, mright), (new_left, mleft-1)
    
  def biggets_substr(self):
    # substr_data = (<repetitions>, <(left, right)>)
    substr_data = (0, (-1, -1))
    substr_size = 0
    for child in self.__root.childrens:
      repetitions, indexes = self.__dfs_for_biggest_susbtr(child)
      child_size = indexes[1] - indexes[0] + 1
      if child_size > substr_size:
        if repetitions > 1:
          substr_size = child_size
          substr_data = repetitions, indexes
      elif child_size == substr_size:
        if repetitions > substr_data[0]:
          substr_size = child_size
          substr_data = repetitions, indexes
     
    return substr_data

  def __dfs_for_biggest_susbtr(self, parent):
    childrens_qtt = len(parent.childrens)
    substr_data = (0,(0,0)) # (0, (0,0))
    substr_size = 0 # 0
    if childrens_qtt == 0:
      return (0, (0, 0))

    for child in parent.childrens:
      repetitions, indexes = self.__dfs_for_biggest_susbtr(child)
      size = indexes[1] - indexes[0] + 1
      if repetitions > 1:
        if size > substr_size:
          substr_data = (repetitions, indexes)
          substr_size = size
        elif size == substr_size:
          if repetitions > substr_data[0]:
            substr_data = (repetitions, indexes)
            substr_size = size

    if substr_data[0] == 0:
      substr_data = (childrens_qtt, parent.sufix)
    else:
      size = parent.sufix[1]-parent.sufix[0]+1
      indexes = substr_data[1]
      substr_data = (substr_data[0], (indexes[0] - size, indexes[1]))
    
    if parent.end_of_string:
      substr_data = (substr_data[0]+1, substr_data[1])

    return substr_data
  
  def graph_to_mermaid(self):
    result = ""
    for child in self.__root.childrens :
      child_name = self.__text[child.sufix[0]: child.sufix[1]+1]
      # child_name = ("(%d, %d)" % (child.sufix[0], child.sufix[1]))
      result += "Root --> " + child_name + "\n"
      result += self.__dfs_to_print(child_name, child)
    return result

  def __dfs_to_print(self, node_name, node):
    s = ""
    for child in node.childrens:
      child_name = self.__text[child.sufix[0]: child.sufix[1]+1]
      # child_name = ("(%d, %d)" % (child.sufix[0], child.sufix[1]))
      s += node_name + " --> " + child_name + "\n"
      s += self.__dfs_to_print(child_name, child)
    return s

def main():
    text = "abcdcdabcd"
    tree = SufixTree(text)
    
    repetitions, indexes = tree.biggets_substr()
    # print(tree.graph_to_mermaid())
    print(repetitions)
    print(text[indexes[0]: indexes[1]+1])

if __name__ == "__main__":
    main()
