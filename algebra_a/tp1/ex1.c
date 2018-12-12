/** Trabalho pratico - questao 1 e 2
*	Vinicius Juliao Ramos
*
*	
*
*
*
*
*
**/

#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>


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
	mpz_t real_number, aux, pows, half_pow, new_pow, base2, aux_pow;
	mpz_t current_powered;
	mpz_init_set(real_number, b);
	//mpz_init_set_ui(wait_number, 1);
	mpz_init_set_ui(pows, 1);
	mpz_init(aux_pow);
	mpz_init(half_pow);
	mpz_init(base2);
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
	mpz_init_set(new_pow, e);
	mpz_init(current_powered);

	while(mpz_cmp(e, pows) > 0){

		mpz_tdiv_q_ui(half_pow, new_pow, 2);
		mpz_set_ui(base2, 1);
		
		mpz_set(current_powered, real_number);

		while(mpz_cmp(half_pow, base2) > 0){
			mpz_set(aux_pow, base2);
			mpz_mul_ui(base2, aux_pow, 2);

			mpz_mul(aux, current_powered, current_powered);
			//mpz_tdiv_r(r, aux, n);
			mpz_tdiv_r(current_powered, aux, n);

			mpz_set(aux_pow, pows);
			mpz_mul_ui(pows, aux_pow, 2);
			//mpz_set(current_powered, r);
		}
//		mpz_set(aux, r);
		mpz_mul(aux, current_powered, r);
		mpz_tdiv_r(r, aux, n);
		//return;
		mpz_tdiv_r(new_pow, e, pows);
	} 
	if(!mpz_cmp_ui(new_pow, 1)){
		mpz_mul(aux, r, real_number);
		mpz_tdiv_r(r, aux, n);
	}

	mpz_clear(real_number);
	mpz_clear(aux);
	mpz_clear(pows);
	mpz_clear(half_pow);
	mpz_clear(new_pow);
	mpz_clear(base2);
	mpz_clear(aux_pow);
	mpz_clear(current_powered);
}

int main(){
	/*mpz_t g, x, y;
	mpz_t a, b, n;

	int inv1, inv2;

	mpz_init_set_ui(b, 7);
	mpz_init_set_ui(a, 13);
	mpz_init_set_ui(n, 0);
	
	mpz_init(x);
	mpz_init(y);
	mpz_init(g);

	//mpz_gcdext(g, x, y, a, b);
	//mdc_estendido(g, x, y, a, b);
	//gmp_printf ("x: %Zd | y: %Zd | g: %Zd\n", x, y, g);
	inv1 = inverso_modular(g, a, n);
	inv2 = mpz_invert (x, a, n);

	if(inv1>0)
	 	gmp_printf ("\n%Zd - %Zd | %Zd %Zd\n", g, x, a, n);

	mpz_clear(x);
	mpz_clear(y);
	mpz_clear(g);
	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(n);*/

	mpz_t r, b, e, n;
	mpz_init_set_ui(b, 2);
	mpz_init_set_ui(e, 15);
	mpz_init_set_ui(n, 10);
	mpz_init(r);

	exp_binaria(r, b , e, n);
	gmp_printf ("\n%Zd\n", r);

	mpz_clear(r);
	mpz_clear(b);
	mpz_clear(e);
	mpz_clear(n);
}