#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	float a, e, f;
	int b, c, d;
	a = 1.5;
	b = 4;
	c = 2;
	d = 3;
	e = 1.2;
	f = 4.3;


	printf("a = %0.1f\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("d = %d\n", d);
	printf("e = %0.1f\n", e);
	printf("f = %0.1f\n", f);

	//formula de V1
	printf("\n");
	printf("      a(c+d)\n");
	printf("V1)  --------  = %f\n", (float)(a*(c+d))/(b*(e+f)));
	printf("      b(e+f)\n");

	//formula de V2
	printf("\n");
	printf("      a^(b+c)\n");
	printf("V2)  --------  = %f\n", (float)(pow(a,b+c))/(e+f));
	printf("       e+f\n");

	//formula de V3 √
	printf("\n");
	printf("      -b + √(b^(2)-4ac)\n");
	printf("V3)  -------------------  = %f\n", (float)(-b + sqrt(pow(b,2)-4*a*c))/(2*a));
	printf("             2a\n");

	return 0;
}