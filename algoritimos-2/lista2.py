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


