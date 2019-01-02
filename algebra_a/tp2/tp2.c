#include <gmp.h>

int talvez_primo(const mpz_t a, const mpz_t n, 
				const mpz_t n1, unsigned int t, const mpz_t q){
	mpz_t aux, restDivision;
	mpz_init(aux);
	mpz_init_set_ui(restDivision, 0);

	mpz_powm(restDivision, a, q, n);

	unsigned int i;
	int value = 0;
	for(i = 0; i < t; i++){

		mpz_set(aux, restDivision);
		if(!mpz_cmp_ui(restDivision, 0)){
			value = 1;
			break;
		}else if(!(mpz_cmp_ui(restDivision, 1)) && i==0){
			value = 1;
			break;
		} else if(!(mpz_cmp(restDivision, n1)) && i >= 0) {
			value = 1;
			break;
		}
		mpz_powm_ui(restDivision, aux, 2, n);
	}
	mpz_clear(restDivision);
	mpz_clear(aux);
	return value;
}

void numero_aleatorio(mpz_t r, const mpz_t n, gmp_randstate_t rnd) {
	mp_bitcnt_t num_bits = mpz_sizeinbase(n, 2);
	do {
		mpz_urandomb(r, rnd, num_bits);
	} while (!(mpz_cmp_ui(r, 1) >= 0 && mpz_cmp(r, n) <= 0));
}


/*
- O numero de miller é da forma (2^k)*q
- Função que obtem o valor de <k> e <q> de acordo com um dado <n>
- <k> é o retorno da funcao e <q> o primeiro parametro obtido
*/
unsigned int fatoracao_em_miller(mpz_t q, const mpz_t n){
	mpz_t resto, aux;
	mpz_init_set_ui(resto, 0);
	mpz_init_set(aux,n);
	unsigned int k;

	for(k=0; 1; k++){
		mpz_tdiv_qr_ui(q, resto, aux, 2);
		if((mpz_cmp_ui(resto, 0))){
			mpz_set(q, aux);
			break;
		}
		mpz_set(aux, q);
	}

	mpz_clear(resto);
	mpz_clear(aux);
	return k;
}


/*
- a intenção final é alterar o seed a cada iteração,\
dessa maneira as chances de se obter uma base repedita diminui

- implementar um vetor para validação se a base ja foi testada\
deixaria o programa muito lento
*/
int provavelmente_primo(const mpz_t n, unsigned int iter, gmp_randstate_t rnd){

	//auxiliar variables
	mpz_t n1, baseToTest, q;
	mpz_init(baseToTest);
	mpz_init(n1);
	mpz_init(q);
	mpz_sub_ui(n1, n, 1);

	//random proccess
	//unsigned long int seed;
	//seed = 45579669;
	//gmp_randseed_ui(rnd, seed);

	//numero de miller
	unsigned int k;
	k = fatoracao_em_miller(q, n1);

	int i, isPrime;
	isPrime = 1;
	for(i=0; i < iter; i++){
		numero_aleatorio(baseToTest, n1, rnd);
		isPrime = talvez_primo(baseToTest, n, n1, k, q);
		if(!isPrime)
			break;

		// changing seed to apply efficiently the random proccess
		//seed+=97;
		//gmp_randseed_ui(rnd, seed);
	}
	mpz_clear(baseToTest);
	mpz_clear(n1);
	mpz_clear(q);
	return isPrime;
}

void primo_aleatorio(mpz_t r, unsigned int b, gmp_randstate_t rnd){
	int isPrime;
	isPrime = 0;
	//unsigned long int seed;
	//seed = 654649876531;
	while(!isPrime){
	//	gmp_randseed_ui(rnd, seed);
		mpz_urandomb(r, rnd, b);
		isPrime = provavelmente_primo(r, 20, rnd);
	//	seed+=97;
	}
}