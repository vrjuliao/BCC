import sufix_tree

def main():
    text = "minimize"
    tree = sufix_tree.SufixTree(text)
    
    repetitions, indexes = tree.biggets_substr()
    print(repetitions)
    print(text[indexes[0]: indexes[1]+1])

if __name__ == "__main__":
    main()