#include <stdio.h>
#include <stdlib.h>
//a
int fat(int n){
	int value;
	for (value = 1; n >= 1; n--){
		value *= n;
	}
	
	return value;
}
//b
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
//c
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

//d
int fib(int fibonacci){
	int firstTerm, secondTerm, aux;
	firstTerm = 0;
	secondTerm = 1;
	int index;
	for(index = 1; index <= fibonacci; index++){
		aux = secondTerm;
		secondTerm = firstTerm;
		firstTerm = aux + firstTerm;
	}
	return firstTerm;
}

//e
// return 1 if true, else return 0
int primo(int num){
	int index;
	for(index = num - 1; index > 1; index--){
		if(num%index == 0) return 1;
	}
	return 0;
}

//f
void decrescente(int num){
	for(; num > 0; num--){
		printf("%d ", num);
	}
}

//g
int res(int numerador, int denominador){
	while(numerador>denominador){
		numerador-=denominador;
	}
	return numerador;
}

//h
int form(int term){
	int index, sum;
	sum = 0;
	for(index=term; index > 0; index--){
		sum+= index*index;
	}
	return sum;
}

//i
int mmc(int a, int b){
	int bigger = a > b ? a : b;
	while(1){
		if((bigger%a == 0) && (bigger%b == 0)){
			return bigger;
		}
		bigger++;
	}
}

//j
int divi(int numerador, int denominador){
	int index;
	for(index = 0; numerador>denominador; index++){
		numerador-=denominador;
	}
	return index;
}

//k
float sqrt1(int num){
	printf("sqrt\n");
	float sqrtNumber = 0.0;
	int aux;
	//finding integer part
	int firstIndex;
	aux = 1;
	for(firstIndex = 0; aux <= num; firstIndex++){
		num -= aux;
		aux+=2;
	}
	sqrtNumber += firstIndex;

	//number * 0.1
	aux = firstIndex*20 +1;
	num *= 100;
	int secondIndex;
	for(secondIndex = 0;aux <= num; secondIndex++){
		num -= aux;
		aux+=2;
	}
	sqrtNumber += 0.1*secondIndex;

	//number * 0.01
	aux = ((firstIndex*10)+secondIndex)*20 +1;
	num *= 100;
	int thirdIndex;
	for(thirdIndex = 0;aux <= num; thirdIndex++){
		num -= aux;
		aux+=2;
	}
	sqrtNumber += 0.01*thirdIndex;	

	//number * 0.001
	aux = ((firstIndex*100)+(secondIndex*10)+thirdIndex)*20 +1;
	num *= 100;
	int fourthIndex;
	for(fourthIndex = 0;aux <= num; fourthIndex++){
		num -= aux;
		aux+=2;
	}
	sqrtNumber += 0.001*fourthIndex;

	return sqrtNumber;
}

int exp(int base, int expoente){
	int resultado = 1;
	for(; expoente > 0; expoente--){
		resultado*=base;
	}
	return resultado;
}

void crescente(int number){
	int index;
	for(index = 1; indez<=number; index++){
		printf("%d ", index);
	}
}

int main (){
	printf("%0.3f\n", sqrt1(30));
	return 0;
}