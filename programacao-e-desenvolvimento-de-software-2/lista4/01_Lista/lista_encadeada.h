#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

#include "node.h"

class ListaEncadeada {
    private:
        Node* _inicio;
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        //void insere_node(Node* value);
        void insere_node(float value);
        void insere_node(Node* n);
        void imprime_lista();
};
#endif