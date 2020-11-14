#include "listaencadeada.h"
#include <iostream>

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


int ListaEncadeada::k_esimo(bool direction, int index){
    if(direction) return get_iesimo(index);
    else {    
        node_t *atual;
        atual = mFim;
        for(int i=0; i<index || atual == nullptr; i++){
            atual = atual->anterior;
        }
        return atual->elemento;    
    }
    
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

bool ListaEncadeada::checa_palindromo(){
    for(int i=0; i<=mSize/2; i++){
        if(k_esimo(true, i) != k_esimo(false, i))
            return false;
    }
    return true;
}

void ListaEncadeada::remover_iesimo(int index){
    
    if(mSize > 0){
        if(index == 0){
            this->remover_primeiro();
            return;
        }
        else if(index == mSize-1){
            this->remover_elemento();
            return;
        } else {
            node_t *atual, *anterior, *proximo;
            atual = get_iesima_referencia(index);
            anterior = atual->anterior;
            proximo = atual->proximo;
       
            if(anterior != nullptr && proximo !=nullptr){
                proximo->anterior = anterior;
                anterior->proximo = proximo;
            } else if(anterior == nullptr){
                proximo->anterior = nullptr;
            } else if(proximo == nullptr){
                anterior->proximo = nullptr;
            }
            delete atual;
            mSize--;
        }
    }
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