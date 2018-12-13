#include "../tp1/ex1.c"
#include "../tp2/tp2_3.c"
#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

void gera_chaves(mpz_t n, mpz_t e, mpz_t d, gmp_randstate_t rnd){
	mpz_t prime_p, prime_q, phi;
	mpz_t prime_p_m1, prime_q_m1;
	mpz_init(prime_q);
	mpz_init(prime_p);
	mpz_init(prime_p_m1);
	mpz_init(prime_q_m1);
	mpz_init(phi);

	//generatin aleatorie primes
	primo_aleatorio(prime_p, 2048, rnd);
	primo_aleatorio(prime_q, 2048, rnd);
	mpz_mul(n, prime_p, prime_q);

	//applying phi(p*q)
	mpz_sub_ui(prime_q_m1, prime_q, 1);
	mpz_sub_ui(prime_p_m1, prime_p, 1);
	mpz_mul(phi, prime_p_m1, prime_q_m1);


	do {
		primo_aleatorio(e, 2048, rnd);
		//mpz_urandomm(e, rnd, phi);
		gmp_printf ("e: %Zd\n", e);
	} while(!(inverso_modular(d, e, phi)) && (mpz_cmp_ui(e, 65537) < 0) && (mpz_cmp(e, phi) > 0));


	mpz_t aux;
	mpz_init(aux);
	while(mpz_cmp_ui(d, 0) < 0){
		mpz_set(aux, d);
		mpz_add(d, aux, phi);
	}

	mpz_clear(aux);
	mpz_clear(prime_q);
	mpz_clear(prime_p);
	mpz_clear(prime_p_m1);
	mpz_clear(prime_q_m1);
	mpz_clear(phi);
}

int main(){
	mpz_t n, e, d;
	mpz_init(n);
	mpz_init(e);
	mpz_init(d);
	gmp_randstate_t rnd;
	gmp_randinit_default(rnd);
	gmp_randseed_ui(rnd, 9879543213);
	gera_chaves(n, e, d, rnd);

	gmp_printf ("\nn: %Zd  \ne: %Zd  \nd: %Zd\n", n, e, d);
	mpz_clear(n);
	mpz_clear(e);
	mpz_clear(d);
}