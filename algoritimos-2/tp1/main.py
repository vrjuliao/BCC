import sufix_tree
import sys

def main(argv):
    filename = argv[0]
    f_open = open(filename)
    f_open.readline()

    splited_text = f_open.readlines()
    separator = ""
    text = separator.join([s[:-1] for s in splited_text])
    # computing sufixes and create the tree
    tree = sufix_tree.SufixTree(text)

    # get the biggest substring that repeats in the text
    repetitions, indexes = tree.biggest_substr()
    
    print(repetitions)
    print(text[indexes[0]: indexes[1]+1])

if __name__ == "__main__":
    main(sys.argv[1:])