#include "aluno.h"
#include "itemlista.h"

class Lista {
protected:
    ItemLista *frist;
    ItemLista *last
public:
    Lista();
    ItemLista *get_first();
    ItemLIsta *get_item(int index);
    ItemLista *get_last();
    void add_item(Aluno *item, int index);
    void add_frist(Aluno *item);
    void add_last(Aluno *item);
}