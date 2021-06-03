#include <stdio.h>
#include <stdlib.h>

int randFunc(int n) {
	return rand() % n;
}

int main() {
	int i, j, k;
	i = randFunc(10);
	j = randFunc(100);
	k = randFunc(50);

	printf("³­¼ö : %d, %d, %d\n", i, j, k);

	return 0;
}