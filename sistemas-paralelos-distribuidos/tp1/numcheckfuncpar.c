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

struct num_data {
  int is_pal;
  int is_rep;
  int is_sum;
  int is_dou;
  int is_fou;
};

struct th_data {
    long maxnum;
    int ndigits;
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

std::unordered_map<long, num_data*> not_completed = {};


// valida se todas as funções já foram chamadas para determinado numero
// deve ser chamado, somente quando há posse do mutex
void check_all(long orign) {
    num_data *data = not_completed[orign];
    if( data->is_rep == NOT_CHECKED || data->is_sum == NOT_CHECKED ||
        data->is_dou == NOT_CHECKED || data->is_fou == NOT_CHECKED ||
        data->is_pal == NOT_CHECKED ) return;
    

    int all = data->is_pal + data->is_rep + data->is_sum + data->is_dou + data->is_fou;
    if (all>0) {
        match_some_test += 1;
        delete data;
    }
    update_max( orign, all );
}

void *th_is_palindrome(void * arg){
    th_data * dt = (th_data*) arg; 
    int pal;
    for(long n=0; n<= dt->maxnum; ++n){
        digit_t num;
        break_into_digits(n, num, dt->ndigits);
        pal = is_palindrome( num, dt->ndigits );
        palindromes += pal;

        pthread_mutex_lock(&lock);
        if(not_completed.find(n) == not_completed.end()){
            not_completed[n] = new num_data{-1, -1, -1, -1, -1};
        }
        not_completed[n]->is_pal = pal;

        check_all(n);
        pthread_mutex_unlock(&lock);
    }
}

void *th_has_repeated_seq(void * arg){
    th_data * dt = (th_data*) arg; 
    int rep;
    for(long n=0; n <= dt->maxnum; ++n){
        digit_t num;
        break_into_digits(n, num, dt->ndigits);
        rep = has_repeated_seq( num, dt->ndigits );
        repeated_seqs += rep;

        pthread_mutex_lock(&lock);
        if(not_completed.find(n) == not_completed.end()){
            not_completed[n] = new num_data{-1, -1, -1, -1, -1};
        }
        not_completed[n]->is_rep = rep;

        check_all(n);
        pthread_mutex_unlock(&lock);
    }
}

void *th_sum_is_ap(void * arg){
    th_data * dt = (th_data*) arg; 
    int sum;
    for(long n=0; n<= dt->maxnum; ++n){
        digit_t num;
        break_into_digits(n, num, dt->ndigits);
        sum = sum_is_ap( num, dt->ndigits );
        sums_are_ap += sum;

        pthread_mutex_lock(&lock);
        if(not_completed.find(n) == not_completed.end()){
            not_completed[n] = new num_data{-1, -1, -1, -1, -1};
        }
        not_completed[n]->is_sum = sum;

        check_all(n);
        pthread_mutex_unlock(&lock);
    }
}

void *th_has_tripled_digits(void * arg){
    th_data * dt = (th_data*) arg; 
    int dou;
    for(long n=0; n<= dt->maxnum; ++n){
        digit_t num;
        break_into_digits(n, num, dt->ndigits);
        dou = has_tripled_digits( num, dt->ndigits );
        have_tripled_digits += dou;

        pthread_mutex_lock(&lock);
        if(not_completed.find(n) == not_completed.end()){
            not_completed[n] = new num_data{-1, -1, -1, -1, -1};
        }
        not_completed[n]->is_dou = dou;

        check_all(n);
        pthread_mutex_unlock(&lock);
    }
}

void *th_has_four_repetitions(void * arg){
    th_data * dt = (th_data*) arg; 
    int fou;
    for(long n=0; n<= dt->maxnum; ++n){
        digit_t num;
        break_into_digits(n, num, dt->ndigits);
        fou = has_four_repetitions( num, dt->ndigits );
        have_four_repetitions += fou;

        pthread_mutex_lock(&lock);
        if(not_completed.find(n) == not_completed.end()){
            not_completed[n] = new num_data{-1, -1, -1, -1, -1};
        }
        not_completed[n]->is_fou = fou;

        check_all(n);
        pthread_mutex_unlock(&lock);
    }
}

int
main( int argc, char* argv[] )
{
    int  ndigits; // núm. de dígitos para representar até o maior número

    long i, tmp;

    th_data dt = th_data();
    struct timeval t1, t2; // marcação do tempo de execução

    dt.maxnum = atol(argv[1]);

    // determinação de ndigits em função do maxnum
    tmp = dt.maxnum;
    dt.ndigits=0;
    do {
        dt.ndigits++;
        tmp=tmp/10;
    } while (tmp>0);
    pthread_t tid[MAX_THREADS];
 
    // Marca o tempo e checa cada número na faixa definida.
    // Note que o valor do parâmetro maxnum é considerado inclusive (<=)
    gettimeofday(&t1,NULL);

    pthread_create(&(tid[0]), NULL, th_is_palindrome, (void*) &dt);
    pthread_create(&(tid[1]), NULL, th_has_repeated_seq, (void*) &dt);
    pthread_create(&(tid[2]), NULL, th_sum_is_ap, (void*) &dt);
    pthread_create(&(tid[3]), NULL, th_has_tripled_digits, (void*) &dt);
    pthread_create(&(tid[4]), NULL, th_has_four_repetitions, (void*) &dt);
    
    for (i=0;i < MAX_THREADS;++i) {
        pthread_join(tid[i], NULL);
    }

    gettimeofday(&t2,NULL);

    // Escrita das estatísticas ao final da execução
    printf("%ld match_some_test (%d%%)\n", match_some_test, (int)((100.0*match_some_test)/dt.maxnum));
    printf("%ld palindromes\n", palindromes);
    printf("%ld repeated_seqs\n", repeated_seqs);
    printf("%ld sums_are_ap\n", sums_are_ap);
    printf("%ld have_tripled_digits\n", have_tripled_digits);
    printf("%ld have_four_repetitions\n", have_four_repetitions);
    print_max( dt.ndigits );
    printf("\ntempo: %lf\n",timediff(&t2,&t1));
}
