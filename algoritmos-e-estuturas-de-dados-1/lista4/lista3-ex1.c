#include <stdio.h>
#include <stdlib.h>

int fat(int n){
	int value;
	for (value = 1; n >= 1; n--){
		value *= n;
	}
	
	return value;
}

int mdc(int a, int b){
	int smaller;
	if(a<=b)
		smaller = a;
	else 
		smaller = b;

	for(;smaller > 0; smaller--){
		if(a%smaller == 0 && b%smaller == 0)
			return smaller;
	}
}

int mdc3(int a, int b, int c){
	int smaller;
	if(a<=b && a<=c)
		smaller = a;
	else if(b<=a && b<=c)
		smaller = b;
	else 
		smaller = c;

	for(;smaller > 0; smaller--){
		if(a%smaller == 0 && b%smaller == 0 && c%smaller == 0)
			return smaller;
	}
}

int main (){
	printf("%d\n", mdc3(30, 20, 10));
	return 0;
}