#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

int talvez_primo(const mpz_t a, const mpz_t n, 
				const mpz_t n1, unsigned int t, const mpz_t q){
	mpz_t aux, restDivision;
	mpz_init(aux);
	mpz_init_set_ui(restDivision, 0);

	mpz_powm(restDivision, a, q, n);
	//gmp_printf("%Zd \n", restDivision);
	unsigned int i;
	int value = 0;
	for(i = 0; i < t; i++){

		mpz_set(aux, restDivision);
		//mpz_tdiv_r (restDivision, oddNumber, n);
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

int provavelmente_primo(const mpz_t n, unsigned int iter, gmp_randstate_t rnd){
	
}

int main(){
	mpz_t resto, a, n, n1, q;
	mpz_init(resto);
	mpz_init_set_si(a, 184);
	mpz_init_set_ui(n, 97);
	mpz_init_set_ui(q, 3);
	mpz_init_set_ui(n1, 96);
	//mpz_powm_ui(resto, a, 2, n);

	int i;
	i = talvez_primo(a, n, n1, 5, q);

	//gmp_printf("%Zd \n", resto);
	printf("%d \n", i);
	//printf("qualquer coisa \n");
	//getchar();
	return 1;
}