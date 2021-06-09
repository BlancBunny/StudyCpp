#include <stdio.h>

int main() {
	int sum = 124, num = 5;
	
	printf("%d / %d = %.2f\n", sum, num, sum / static_cast<double>(num));
	
}

