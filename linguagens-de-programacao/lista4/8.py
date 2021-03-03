import traceback
class FormulaError(Exception):
  pass

while True:
  try:
    line = input()
    data = line.split(' ')
    if(len(data) != 3):
      raise FormulaError('A entrada nao consiste de 3 elementos')
    try:
      val1 = float(data[0])
      val2 = float(data[2])
      op = data[1]
    except ValueError:
      raise FormulaError('O primeiro e o terceiro valor da entrada devem ser numeros')

    if(op == '+'): print(val1+val2)
    elif(op == '-'): print(val1-val2)
    elif(op == '*'): print(val1*val2)
    elif(op == '/'): print(val1/val2)
    else : raise FormulaError(op+' nao e um operador valido')
  except FormulaError:
    traceback.print_exc()
  