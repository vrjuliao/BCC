import sufix_tree

def main():
    tree = sufix_tree.SufixTree("minimize")
    print(tree.graph_to_mermaid())

if __name__ == "__main__":
    main()