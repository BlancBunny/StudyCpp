#include <stdio.h>

int main() {
	int num;

	try {
		printf("1���� 100���� ���� �Է� : ");
		scanf_s("%d", &num);
		if (num < 1 || num > 100) throw num;
		printf("�Է��� �� : %d\n", num);
	}

	catch (int num) {
		printf("%d : ���� �ʰ�\n", num);
	}

	return 0;
}