#include "node.h"
#include "listaencadeada.h"

Node::Node(int elemento){
    mElemento = elemento;
    mDireita = nullptr;
    mEsquerda = nullptr;
}

void Node::inserir_elemento(int elemento){
    if(elemento < mElemento){
        if(mEsquerda == nullptr){
            Node *new_node = new Node(elemento);
            mEsquerda = new_node;
        } else {
            mEsquerda->inserir_elemento(elemento);
        }
    } else {
        if(mDireita == nullptr){
            Node *new_node = new Node(elemento);
            mDireita = new_node;
        } else {
            mDireita->inserir_elemento(elemento);
        }
    }
}

bool Node::existe_elemento(int elemento){
    if(elemento == mElemento){
        return true;
    } else {
        if(mElemento > elemento){
            if(mEsquerda!=nullptr)
                return mEsquerda->existe_elemento(elemento);
            else 
                return false;
        } else {
            if(mDireita!=nullptr)
                return mDireita->existe_elemento(elemento);
            else 
                return false;
        }
    }
    return false;
}

Node::~Node(){
    if(mEsquerda != nullptr)
        delete mEsquerda;
    if(mDireita != nullptr)
        delete mDireita;
}

ListaEncadeada Node::pre_ordem(){
    ListaEncadeada list;
    _pre_ordem(list);
    return list;
}

void Node::_pre_ordem(ListaEncadeada &list){
    list.insere_elemento(mElemento);
    if(mEsquerda!=nullptr)
        mEsquerda->_pre_ordem(list);
    if(mDireita!=nullptr)
        mDireita->_pre_ordem(list);
}

ListaEncadeada Node::em_ordem(){
    ListaEncadeada list;
    _em_ordem(list);
    return list;
}

void Node::_em_ordem(ListaEncadeada &list){
    if(mEsquerda!=nullptr)
        mEsquerda->_em_ordem(list);
    list.insere_elemento(mElemento);
    if(mDireita!=nullptr)
        mDireita->_em_ordem(list);
}

ListaEncadeada Node::pos_ordem(){
    ListaEncadeada list;
    _pos_ordem(list);
    return list;
}

void Node::_pos_ordem(ListaEncadeada &list){
    if(mEsquerda!=nullptr)
        mEsquerda->_pos_ordem(list);
    if(mDireita!=nullptr)
        mDireita->_pos_ordem(list);
    list.insere_elemento(mElemento);
}