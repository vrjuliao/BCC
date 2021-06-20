/* Você deve implementar uma versão usando paralelismo de dados (também
 * chamado decomposição/partição de domínio (domain partition/decomposition)
 * Para simplificar, você pode considerar que seu programa criará oito
 * threads para processar todos os números. Todas as threads devem executar
 * o mesmo código, já que estarão executando as mesmas operações para
 * partes diferentes do conjunto de dados.
 * 
 * O programa deve aceitar o mesmo parâmetro de linha de comando da versão
 * sequencial - e nenhum outro. 
 * A saída deve sequir exatamente o mesmo formato da versão sequencial.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

#include "timediff.h"   // calcula tempo decorrido
#include "numchecks.h"  // conta números com mais condições válidas
#include "conditions.h" // verifica cada condição

#define MAX_THREADS 4

pthread_mutex_t lock;

typedef struct th_attributes 
{
  long min, max;
  int ndigits;
} th_attributes;

// Contadores para cada uma das condições testadas
long match_some_test = 0,
     palindromes = 0,
     repeated_seqs = 0,
     sums_are_ap = 0,
     have_tripled_digits = 0,
     have_four_repetitions = 0;


/* check_num: concentra todos os testes a serem aplicados a cada número.
 */
void* check_num(void* arg) //(long n, int ndigits)
{
    int all, pal, rep, sum, dou, fou;
    digit_t num;

    th_attributes *attr = (th_attributes *)(arg);
    
    long orign;
    for(long n = attr->min; n <= attr->max; ++n) {
        orign = n;

        // Transforma número (n) em vetor de dígitos (num)
        break_into_digits(n, num, attr->ndigits);

        // Aplica os diversos testes a um dado número
        pal = is_palindrome( num, attr->ndigits );
        rep = has_repeated_seq( num, attr->ndigits );
        sum = sum_is_ap( num, attr->ndigits );
        dou = has_tripled_digits( num, attr->ndigits );
        fou = has_four_repetitions( num, attr->ndigits );

        // Para processar número de condições satisfeitas
        all = pal + rep + sum + dou + fou;

        pthread_mutex_lock(&lock);
        // Atualiza os contadores por condição
        palindromes += pal;
        repeated_seqs += rep;
        sums_are_ap += sum;
        have_tripled_digits += dou;
        have_four_repetitions += fou;
        if (all>0) {
            match_some_test += 1;
        }
        update_max( orign, all );
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int
main( int argc, char* argv[] )
{
    int  ndigits; // núm. de dígitos para representar até o maior número

    long i, tmp, maxnum;
        
    struct timeval t1, t2; // marcação do tempo de execução

    // tratamento da linha de comando
    if (argc!=2) {
        fprintf(stderr,"usage: %s maxnum\n",argv[0]);
        exit(1);
    }
    maxnum = atol(argv[1]);

    // determinação de ndigits em função do maxnum
    tmp = maxnum;
    ndigits=0;
    do {
        ndigits++;
        tmp=tmp/10;
    } while (tmp>0);
    
    gettimeofday(&t1,NULL);
    if(ndigits > 0) {    
        // thread attributes
        th_attributes attr[MAX_THREADS];
        pthread_t tid[MAX_THREADS];

        if (pthread_mutex_init(&lock, NULL) != 0) {
            printf("\n mutex init has failed\n");
            return 1;
        }

        // Particionamento de dados
        long part = maxnum / MAX_THREADS;
        for(long i = 0; i<MAX_THREADS; ++i){
            attr[i].min = i*part;
            attr[i].max = ((i+1)*part)-1;
            attr[i].ndigits = ndigits;
        }
        attr[MAX_THREADS-1].max = maxnum;

        // Dadas as 4 threads que serão criadas para a paralelização de dados, 
        // calcula-se o intervalo de ação de cada thread.
        for (i=0;i < MAX_THREADS;++i) {
            if (pthread_create(&(tid[i]), NULL, check_num, (void*) &attr[i]) < 0) {
                printf("Thread creation error\n");
                exit(EXIT_FAILURE);
            }
        }
        for (i=0;i < MAX_THREADS;++i) {
            pthread_join(tid[i], NULL);
        }

        pthread_mutex_destroy(&lock);
    }
    gettimeofday(&t2,NULL); 
    // Escrita das estatísticas ao final da execução
    printf("%ld match_some_test (%d%%)\n", match_some_test, (int)((100.0*match_some_test)/maxnum));
    printf("%ld palindromes\n", palindromes);
    printf("%ld repeated_seqs\n", repeated_seqs);
    printf("%ld sums_are_ap\n", sums_are_ap);
    printf("%ld have_tripled_digits\n", have_tripled_digits);
    printf("%ld have_four_repetitions\n", have_four_repetitions);
    print_max( ndigits );
    printf("\ntempo: %lf\n",timediff(&t2,&t1));
}
