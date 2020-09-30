#include <stdio.h>
#include <stdlib.h>

float equilatero (Triangulo tr){
	float distancia1, distancia2, distancia3;
	distancia1 = sqrt(pow(tr.A.x-tr.B.x, 2) + pow(tr.A.y-tr.B.y, 2));
	distancia2 = sqrt(pow(tr.A.x-tr.C.x, 2) + pow(tr.A.y-tr.C.y, 2));
	distancia3 = sqrt(pow(tr.C.x-tr.B.x, 2) + pow(tr.C.y-tr.B.y, 2));

	if(distancia3 == distancia1 && distancia1 == distancia2)
		return 1;

	return 0;
}
