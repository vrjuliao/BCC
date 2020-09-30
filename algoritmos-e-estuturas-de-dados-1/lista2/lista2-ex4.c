#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]){
	float circumferenceRadius;
	printf("Raio da circunferência:");
	scanf("%f", &circumferenceRadius);

	float circumferencePerimeter;
	circumferencePerimeter = 2 * circumferenceRadius * M_PI;
	printf("Perímetro da circunferência: %f\n", circumferencePerimeter);
	
	float circumferenceArea;
	circumferenceArea = pow(circumferenceRadius,2) * M_PI;
	printf("Area da circunferência: %f\n", circumferenceArea);
	return 0;
}