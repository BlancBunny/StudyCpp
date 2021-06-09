#include <stdio.h>

int main() {
	int num;

	try {
		printf("1부터 100까지 정수 입력 : ");
		scanf_s("%d", &num);
		if (num < 1 || num > 100) throw num;
		printf("입력한 수 : %d\n", num);
	}

	catch (int num) {
		printf("%d : 범위 초과\n", num);
	}

	return 0;
}