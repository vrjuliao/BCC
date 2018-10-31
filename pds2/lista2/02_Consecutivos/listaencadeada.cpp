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
    this->remove_consecutivos();
}

void ListaEncadeada::insere_primeiro(int valor){
    node_t *atual = new node_t;
    atual->elemento = valor;
    atual->anterior = nullptr;
    if(mInicio == nullptr){
        atual->anterior = nullptr;
        mInicio = atual;
        mFim = atual;
    } else {
        mInicio->anterior = atual;
        atual->proximo = mInicio;
        mInicio = atual;
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

void ListaEncadeada::inserir_iesimo(int elemento, int index){
    node_t *atual, *proximo, *anterior;
    atual = new node_t;
    atual->elemento = elemento;
    proximo = get_iesima_referencia(index);
    anterior = proximo->anterior;
    atual->anterior = anterior;
    atual->proximo = proximo;
    proximo->anterior = atual;
    anterior->proximo = atual;
    mSize++;
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

int ListaEncadeada::tamanho(){
    return mSize;
}

void ListaEncadeada::remove_consecutivos(){
    node_t *atual, *proximo, *anterior;
    atual = mInicio;
    
    while(atual->proximo!=nullptr){
        proximo = atual->proximo;    
        //int valorAtual, valorProximo;
        //valorAtual = atual->elemento;
        //valorProximo = proximo->elemento;
        if(proximo!=nullptr && atual->elemento != proximo->elemento){
            //std::cout<< (proximo!=nullptr) <<"   " << ((valorAtual) != (valorProximo)) << "   ";
            
            //std::cout<< atual->elemento <<" pulou " << proximo->elemento << std::endl;
            atual = proximo;
            
        } else if(proximo->elemento == atual->elemento){
            //std::cout<< atual->elemento <<" entrou " << proximo->elemento<<std::endl;
            anterior = proximo;
            proximo = proximo->proximo;
            atual->proximo = proximo;
            delete anterior;
            mSize--;
            if(proximo==nullptr) {
                mFim = atual;
            } else {
                proximo->anterior = atual;
            }
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