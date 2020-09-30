#include "../tp1/ex1.c"
#include "../tp2/tp2_3.c"
#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <string.h>

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
		// gmp_printf ("e: %Zd\n", e);
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

void codifica(mpz_t r, const char *str){
	int length, index, index_pow;
	unsigned long int ascii_number;

	mpz_t gmp_ascii_number, gmp_index_char, aux;
	mpz_init(gmp_ascii_number);
	mpz_init(aux);
	mpz_init_set_ui(gmp_index_char, 1);
	mpz_set_ui(r, 0);

	length = strlen(str);

	for(index = 0; index <= length; index++){
		ascii_number = *(str + index);
		// gmp_printf ("char: %c, ascii_number: %ld\n", *(str+index), ascii_number);
		mpz_set_ui(gmp_ascii_number, ascii_number);
		mpz_mul(aux, gmp_ascii_number, gmp_index_char);
		// gmp_printf ("ascII number position: %Zd\n", aux);

		mpz_set(gmp_ascii_number, r);
		mpz_add(r, gmp_ascii_number, aux);

		mpz_set(aux, gmp_index_char);
		mpz_mul_ui(gmp_index_char, aux, 256);
	}

	mpz_clear(gmp_ascii_number);
	mpz_clear(aux);
	mpz_clear(gmp_index_char);
}

char *decodifica (const mpz_t n){
	char *str, *straux;
	mpz_t value, aux, current_rest, last_rest, pow256, pow256_plus;
	mpz_init_set_ui(current_rest, 0);
	mpz_init_set_ui(last_rest, 0);
	mpz_init_set(value, n);
	mpz_init_set_ui(pow256, 1);
	mpz_init_set_ui(pow256_plus, 256);
	mpz_init(aux);

	// str = (char *)malloc(1 * sizeof(char));
	str = (char *)malloc(500 * sizeof(char));
	int max_index_of_string;
	max_index_of_string = 0;
	mpz_tdiv_r(current_rest, n, pow256_plus);
	mpz_sub(aux, current_rest, last_rest);
	mpz_tdiv_q(value, aux, pow256);
	str[max_index_of_string] = mpz_get_ui(value);
	// gmp_printf ("value string %c\n", str[max_index_of_string]);
	
	for(max_index_of_string = 1; mpz_cmp(current_rest, n); max_index_of_string++){
		mpz_set(pow256, pow256_plus);
		mpz_mul_ui(pow256_plus, pow256, 256);
		mpz_tdiv_r(current_rest, n, pow256_plus);
		mpz_sub(aux, current_rest, last_rest);
		mpz_tdiv_q(value, aux, pow256);
		str[max_index_of_string] = mpz_get_ui(value);
		//straux = (char *)realloc(str, max_index_of_string+1 * sizeof(char));
		//str = straux;
		//gmp_printf ("value: %Zd\n", value);
		str[max_index_of_string] = mpz_get_ui(value);
		// gmp_printf ("value string %c\n", str[max_index_of_string]);
	}
	straux = (char *)realloc(str, max_index_of_string+1 * sizeof(char));
	str = straux;
	//gmp_printf ("value: %Zd\n", value);
	str[max_index_of_string] = '\0';
	/*
	mpz_tdiv_r_ui(rest, n, 256*256*256);
	gmp_printf ("\n\n numero: %Zd\n", rest);
	mpz_clear(rest);
	*/
	mpz_clear(current_rest);
	mpz_clear(last_rest);
	mpz_clear(value);
	mpz_clear(pow256);
	mpz_clear(pow256_plus);
	mpz_clear(aux);

	return str;
}


void criptografa(mpz_t C, const mpz_t M, const mpz_t n, const mpz_t e){
	exp_binaria(C, M, e, n);
}

void descriptografa(mpz_t M, const mpz_t C, const mpz_t n, const mpz_t d){
	exp_binaria(M, C, d, n);
}

int main(){
	mpz_t n, e, d, M, C;
	mpz_init(n);
	mpz_init(e);
	mpz_init(d);
	mpz_init(M);
	mpz_init(C);
	gmp_randstate_t rnd;
	gmp_randinit_default(rnd);
	gmp_randseed_ui(rnd, 9879543213);
	gera_chaves(n, e, d, rnd);
	codifica(M, "hr5VF4+rSGJiP1cKLMFphi0s5FeDfnjH/7JeeJzS");
	gmp_printf ("\nMensagem codificada: %Zd\n", M);

	criptografa(C, M, n, e);
	gmp_printf ("\nMensagem criptografa: %Zd\n", C);
	
	descriptografa(M, C, n, d);
	gmp_printf ("\nMensagem descriptografa: %Zd\n", M);

	char* str;
	str = decodifica(M);
	gmp_printf ("Mensagem original: %s\n", str);
	mpz_clear(n);
	mpz_clear(e);
	mpz_clear(d);
	mpz_clear(M);
	mpz_clear(C);
}