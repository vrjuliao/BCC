/* Você deve implementar uma versão usando paralelismo de funções (também
 * chamado decomposição por funções (function decomposition)
 * Para simplificar, você pode considerar que seu programa criará as
 * threads que você julgar necessárias para processar todos os números,
 * onde cada thread executará uma função diferente, com parte das ações
 * esperadas do programa final.
 * 
 * O programa deve aceitar o mesmo parâmetro de linha de comando da versão
 * sequencial - e nenhum outro. 
 * A saída deve sequir exatamente o mesmo formato da versão sequencial.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <unordered_map>

extern "C" {
    #include "timediff.h"   // calcula tempo decorrido
    #include "numchecks.h"  // conta números com mais condições válidas
    #include "conditions.h" // verifica cada condição
}

#define MAX_THREADS 5

struct th_data {
    long maxnum;
    int ndigits;
    int type;
};

static const int NOT_CHECKED = -1;

// Contadores para cada uma das condições testadas
long match_some_test = 0,
     palindromes = 0,
     repeated_seqs = 0,
     sums_are_ap = 0,
     have_tripled_digits = 0,
     have_four_repetitions = 0;

pthread_mutex_t lock;

std::unordered_map<long, int*> _not_completed = {};
static const int PAL = 0, REP = 1, SUM = 2, HTD = 3, HFR = 4;

// valida se todas as funções já foram chamadas para determinado numero
// deve ser chamado, somente quando há posse da mutex
void _check_all(long orign) {
    int *data = _not_completed[orign];
    int all = 0;
    for(int i=0; i<5; ++i){
        if (data[i] == NOT_CHECKED) return;
        all += data[i];
    }

    if (all>0) {
        match_some_test += 1;
        free(_not_completed[orign]);
        _not_completed.erase(orign);
    }
    update_max( orign, all );
}

void *check_num(void * arg){
    th_data * dt = (th_data*) arg;
    long* property;
    int (*check_property)(digit_t, int);

    // Seleciona qual das funções será executada na thread
    // de acordo com o argumento `type`
    switch (dt->type) {
        case PAL:
            check_property = &is_palindrome;
            property = &palindromes;
            break;
        case REP:
            check_property = &has_repeated_seq;
            property = &repeated_seqs;
            break;
        case SUM:
            check_property = &sum_is_ap;
            property = &sums_are_ap;
            break;
        case HTD:
            check_property = &has_tripled_digits;
            property = &have_tripled_digits;
            break;
        case HFR:
            check_property = &has_four_repetitions;
            property = &have_four_repetitions;
            break;
    }

    int catched_prop;
    for(long n=0; n<= dt->maxnum; ++n){
        digit_t num;
        break_into_digits(n, num, dt->ndigits);

        catched_prop = check_property( num, dt->ndigits );
        (*property) += catched_prop;

        pthread_mutex_lock(&lock);
        if(_not_completed.find(n) == _not_completed.end()){
            int *v = (int*) malloc(5*sizeof(int));
            for(int i=0; i<5; ++i)
                v[i] = NOT_CHECKED;
            _not_completed[n] = v;
        }
        _not_completed[n][dt->type] = catched_prop;

        _check_all(n);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int
main( int argc, char* argv[] )
{
    long i, tmp;

    th_data dt[MAX_THREADS];
    struct timeval t1, t2; // marcação do tempo de execução

    dt[PAL].maxnum = atol(argv[1]);

    // determinação de ndigits em função do maxnum
    tmp = dt[PAL].maxnum;
    dt[PAL].ndigits=0;
    do {
        dt[PAL].ndigits++;
        tmp=tmp/10;
    } while (tmp>0);
    pthread_t tid[MAX_THREADS];
 
    // Marca o tempo e checa cada número na faixa definida.
    // Note que o valor do parâmetro maxnum é considerado inclusive (<=)
    gettimeofday(&t1,NULL);

    for (i=0;i < MAX_THREADS;++i) {
        dt[i] = dt[0];
        dt[i].type = i;
        pthread_create(&(tid[i]), NULL, check_num, (void*) &dt[i]);
    }
    
    for (i=0;i < MAX_THREADS;++i) {
        pthread_join(tid[i], NULL);
    }

    gettimeofday(&t2,NULL);

    // Escrita das estatísticas ao final da execução
    printf("%ld match_some_test (%d%%)\n", match_some_test, (int)((100.0*match_some_test)/dt[0].maxnum));
    printf("%ld palindromes\n", palindromes);
    printf("%ld repeated_seqs\n", repeated_seqs);
    printf("%ld sums_are_ap\n", sums_are_ap);
    printf("%ld have_tripled_digits\n", have_tripled_digits);
    printf("%ld have_four_repetitions\n", have_four_repetitions);
    print_max( dt[0].ndigits );
    printf("\ntempo: %lf\n",timediff(&t2,&t1));
}
