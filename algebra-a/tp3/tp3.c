#include <gmp.h>
#include <stdlib.h>
#include <string.h>

void mdc_estendido(mpz_t g, mpz_t x, mpz_t y, const mpz_t a, const mpz_t b){
	// ax + by = g
	//gmp_printf ("x: %Zd | y: %Zd | g: %Zd | a: %Zd | b: %Zd\n", x, y, g, a, b);
	if(!mpz_cmp_ui(b, 0)){
		mpz_set(g, a);
		mpz_set_ui(x, 1);
		mpz_set_ui(y, 0);

	} else if(!mpz_cmp_ui(a, 0)){
		mpz_set(g, b);
		mpz_set_ui(x, 0);
		mpz_set_ui(y, 1);
	}
	else {
		mpz_t _r, _aux, _q;
		mpz_init(_r);
		mpz_init(_q);
		mpz_init(_aux);
	
		mpz_tdiv_r(_r, a, b);
	//gmp_printf ("r: %Zd \n", _r);
		if(!mpz_cmp_ui(_r, 0)){
			mpz_set(g, b);
			mpz_set_ui(x, 0);
			mpz_set_ui(y, 1);
		} else {
			mdc_estendido(g, x, y, b, _r);
			mpz_tdiv_q(_q, a, b);
			mpz_set(_aux, x);
			mpz_set(x, y);
			mpz_submul(_aux, _q, y);
			mpz_set(y, _aux);
		}
		mpz_clear(_r);
		mpz_clear(_aux);
		mpz_clear(_q);
	}

}

int inverso_modular(mpz_t r, const mpz_t a, const mpz_t n){
	mpz_t g, x, y;
	mpz_init(x);
	mpz_init(y);
	mpz_init(g);

	mdc_estendido(g, x, y, n, a);
	//gmp_printf ("\n%Zd - %Zd | %Zd\n", r, x, g);
	if(!mpz_cmp_ui(g, 1)){
		mpz_set(r, y);
		mpz_clear(x);
		mpz_clear(y);
		mpz_clear(g);
		return 1;
	}
	mpz_clear(x);
	mpz_clear(y);
	mpz_clear(g);
	return 0;
}

void exp_binaria(mpz_t r, const mpz_t b, const mpz_t e, const mpz_t n){
	mpz_t aux, base2_exp, new_exp;
	mpz_t current_base, current_exp;
	

	mpz_set_ui(r, 1);
	mpz_init_set_ui(current_exp, 0);
	mpz_init(new_exp);
	mpz_init(base2_exp);
	mpz_init(current_base);
	mpz_init(aux);
	/*if(mpz_cmp_ui(b, 0) < 0){
		mpz_init(real_number);
		int has_modular_inverse;
		has_modular_inverse = inverso_modular(real_number, b, n);
		if(!has_modular_inverse) 
			exit(1);
	} else {
		mpz_init_set(real_number, b);
	}*/
	
	// new_exp = e / 2
	//mpz_tdiv_q_ui(new_exp, e, 2);

	// rest_new_exp = e - new_exp;
		//mpz_sub(rest_new_exp, e, new_exp);

	//while(current_exp != e)
	while(mpz_cmp(current_exp, e) < 0){
		//new_exp = (e - current_exp)/2;
		mpz_sub(aux, e, current_exp);
		mpz_tdiv_q_ui(new_exp, aux, 2);

		//base2 = 1
		mpz_set_ui(base2_exp, 1);

		//current_base = b;
		mpz_set(current_base, b);
		//while(current_base2_exp < new_exp)
	// gmp_printf ("-----------segundo while-----------\n");
	// gmp_printf ("new_exp: %Zd\n", new_exp);
		//base_aux = 1;
		//mpz_set_ui(base_aux, 1);
		
		//do{
		while(mpz_cmp(base2_exp, new_exp) <= 0){
			mpz_mul(aux, current_base, current_base);
			mpz_tdiv_r(current_base, aux, n);

			//mpz_set(aux, r);
			//mpz_mul(r, current_base, aux);
	// gmp_printf ("current_base: %Zd\n", current_base);

			//base2_exp *= 2;
			mpz_set(aux, base2_exp);
			mpz_mul_ui(base2_exp, aux, 2);
		}// while(mpz_cmp(base2_exp, new_exp) < 0);

		mpz_set(aux, r);
		mpz_mul(r, current_base, aux);
		mpz_set(aux, r);
		mpz_tdiv_r(r, aux, n);
	// gmp_printf ("r: %Zd\n", r);

		//current_exp += base2_exp;
		mpz_set(aux, current_exp);
		mpz_add(current_exp, aux, base2_exp);
	//gmp_printf ("current_exp: %Zd\n", current_exp);
	}

	// gmp_printf ("\n");

	mpz_clear(current_exp);
	mpz_clear(new_exp);
	mpz_clear(base2_exp);
	mpz_clear(current_base);
	mpz_clear(aux);
}

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