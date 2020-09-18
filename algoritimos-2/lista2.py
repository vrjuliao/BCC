def shift_and_table(pattern):
    plen = len(pattern)
    symbols = dict() 

    # aaaaabassda
    for index in range(plen):
        s = "0"*(plen-index-1)+'1'
        if pattern[index] in symbols:
            concat_string =  symbols[pattern[index]][plen-index:]
        else:
            concat_string =  '0'*index
        symbols[pattern[index]] = s+concat_string

    for key, value in symbols.items(): print(key, value)

def horspol_table(P):
    m = len(P)
    Table = dict((c,m) for c in P) 

    # aaaaabassda
    for i in range(m-1):
        Table[P[i]] = m-1-i
        
    for key, value in Table.items(): print(key, value)

def prefix_table(s):
  prefix = [0 for _ in s]
  j = 0
  for i in range(1, len(s), 1):
    while j>0 and s[j] != s[i]:
      j = prefix[j-1]

    if s[j] == s[i]:
      j += 1

    prefix[i] = j

  return prefix

def prefix_table_(s):
  prefix = prefix_table(s)
  new_prefix = [p for p in prefix]
  for i in range(1, len(s)-1, 1):
    a = prefix[i]
    if a == 0:
      new_prefix[i] = 0
    elif s[a+1] == s[i+1]:
      new_prefix[i] = new_prefix[prefix[i]]

  return new_prefix
