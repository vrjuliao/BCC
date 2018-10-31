#ifndef PDS2_NODE_H
#define PDS2_NODE_H
#include "listaencadeada.h"

class Node {
private:
    Node *mEsquerda;
    Node *mDireita;
    int mElemento;
    
    void _pre_ordem(ListaEncadeada &list);
    void _em_ordem(ListaEncadeada &list);
    void _pos_ordem(ListaEncadeada &list);
public:
    Node(int valor);
    ~Node();
    void inserir_elemento(int elemento);
    bool existe_elemento(int elemento);
    ListaEncadeada pre_ordem();
    ListaEncadeada em_ordem();
    ListaEncadeada pos_ordem();
};
#endif
