#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

struct node_t {
	int elemento;
	node_t *proximo;
	node_t *anterior;
};

class ListaEncadeada {
    private:
        node_t *mInicio, *mFim;
        node_t* get_iesima_referencia(int);
        int mSize;
        
    public:
        ListaEncadeada();
        void insere_elemento(int);
        int get_iesimo(int);
        void remover_elemento();
        void remover_primeiro();
        int k_esimo(bool, int);
        bool checa_palindromo();
        void remover_iesimo(int);
        
        ~ListaEncadeada();
};

#endif /* LISTAENCADEADA_H_ */
