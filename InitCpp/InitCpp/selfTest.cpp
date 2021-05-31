#include <stdio.h>

int main() {
	double* ar = new double[100];
	ar[50] = 3.14;

	printf("%d¹øÂ° = %.2lf", 50, ar[50]);

	delete[] ar;

	return 0;
}