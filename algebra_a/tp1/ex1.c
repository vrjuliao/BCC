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
			mpz_set(current_base, aux);
			//mpz_set(aux, r);
			//mpz_mul(r, current_base, aux);
	// gmp_printf ("current_base: %Zd\n", current_base);

			//base2_exp *= 2;
			mpz_set(aux, base2_exp);
			mpz_mul_ui(base2_exp, aux, 2);
		}// while(mpz_cmp(base2_exp, new_exp) < 0);

		mpz_set(aux, r);
		mpz_mul(r, current_base, aux);
	// gmp_printf ("r: %Zd\n", r);

		//current_exp += base2_exp;
		mpz_set(aux, current_exp);
		mpz_add(current_exp, aux, base2_exp);
	//gmp_printf ("current_exp: %Zd\n", current_exp);
	}

	gmp_printf ("\n");

	mpz_clear(current_exp);
	mpz_clear(new_exp);
	mpz_clear(base2_exp);
	mpz_clear(current_base);
	mpz_clear(aux);
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
	mpz_init_set_ui(b, 3);
	mpz_init_set_ui(e, 19);
	mpz_init_set_ui(n, 10);
	mpz_init(r);

	exp_binaria(r, b , e, n);
	gmp_printf ("\n%Zd\n", r);

	mpz_clear(r);
	mpz_clear(b);
	mpz_clear(e);
	mpz_clear(n);
}