#include "listaencadeada.h"

ListaEncadeada::ListaEncadeada(){
    mInicio = nullptr;   
    mFim = nullptr;   
    mSize = 0;
}

void ListaEncadeada::insere_elemento(int valor){
    node_t *atual = new node_t;
    atual->elemento = valor;
    atual->proximo = nullptr;
    if(mInicio == nullptr){
        atual->anterior = nullptr;
        mInicio = atual;
        mFim = atual;
    } else {
        mFim->proximo = atual;
        atual->anterior = mFim;
        mFim = atual;
    }
    mSize++;
}

node_t* ListaEncadeada::get_iesima_referencia(int index){
    node_t *atual;
    atual = mInicio;
    for(int i=0; i<index || atual == nullptr; i++){
        atual = atual->proximo;
    }
    return atual;
}

int ListaEncadeada::get_iesimo(int index){
    node_t *atual = get_iesima_referencia(index);
    if(atual != nullptr) {
        return atual->elemento;
    }
    return 0;
}

void ListaEncadeada::remover_elemento(){
    node_t *atual;
    atual = mFim;
    mFim = mFim->anterior;
    delete atual;
    if(mFim!=nullptr) mFim->proximo = nullptr;
    mSize--;
}

void ListaEncadeada::remover_primeiro(){
    node_t *atual;
    atual = mInicio;
    mInicio = mInicio->proximo;
    delete atual;
    if(mInicio!=nullptr) mInicio->anterior = nullptr;
    mSize--;
}

int ListaEncadeada::tamanho(){
    return mSize;
}

ListaEncadeada::~ListaEncadeada(){
    node_t *atual;
    while(mInicio != nullptr){
        mInicio->anterior = nullptr;
        atual = mInicio;
        mInicio = mInicio->proximo;
        delete atual;
    }
}