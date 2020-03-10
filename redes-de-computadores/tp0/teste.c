#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char a[12] = {'\0'};
	/*a[0] = '1';
	a[1] = '2';
	a[2] = '3';
	a[3] = '4';*/


	// char b[10];
	// sprintf(b, "%d", a);
	// printf("%zd\n", strlen(b));
	printf("%d\n", atoi(a));
	printf("%zd\n", strlen(a));

	return 0;
}