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

int main(){
	mpz_t g, x, y;
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
	mpz_clear(n);
}