#include <stdio.h>
#include <stdlib.h>

int pontoDentroDaCircunferencia (circunferencia cr, Ponto p){
	float distancia_centro_ponto;
	distancia_centro_ponto = sqrt(pow(cr.centro.x-p.x, 2) + pow(cr.centro.y-p.y, 2));

	return distancia_centro_ponto <= cr.raio;
}
