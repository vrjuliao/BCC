#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char a[12] = {'\0'};
	a[0] = (rand()%94)+33;
	printf("%d\n", a[0]);
	a[1] = (rand()%94)+33;
	printf("%d\n", a[1]);
	a[2] = (rand()%94)+33;
	printf("%d\n", a[2]);
	a[3] = (rand()%94)+33;
	printf("%d\n", a[3]);
	a[4] = (rand()%94)+33;
	printf("%d\n", a[4]);
	a[5] = (rand()%94)+33;
	printf("%d\n", a[5]);
	

	// char b[10];
	// sprintf(b, "%d", a);
	printf("%s\n", a);
	/*printf("%d\n", atoi(a));
	printf("%zd\n", strlen(a));*/

	return 0;
}