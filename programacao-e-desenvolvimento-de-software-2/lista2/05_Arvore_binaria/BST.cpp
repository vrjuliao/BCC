#include "BST.h"
#include "listaencadeada.h"
#include "node.h"

BST::BST(){
    mRaiz = nullptr;
}

BST::~BST(){
    delete mRaiz;
}

void BST::inserir_elemento(int elemento){
    if(mRaiz == nullptr){
        mRaiz = new Node(elemento);
    } else {
        mRaiz->inserir_elemento(elemento);    
    }
}

bool BST::existe_elemento(int elemento){
    return mRaiz->existe_elemento(elemento);
}

ListaEncadeada BST::pre_ordem(){
    if(mRaiz != nullptr)
        return mRaiz->pre_ordem();
    ListaEncadeada l;
    return l;
}

ListaEncadeada BST::em_ordem(){
    if(mRaiz != nullptr)
        return mRaiz->em_ordem();
    ListaEncadeada l;
    return l;
}

ListaEncadeada BST::pos_ordem(){
    if(mRaiz != nullptr)
        return mRaiz->pos_ordem();
    ListaEncadeada l;
    return l;
}