#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	�Ǳ� : ��Ʈ�Ͻ� ȸ������ ���α׷�
	�ű�ȸ�� ����� ȸ�� ��ȣ�� �̸�, ü���� �Է��ϰ�, heap ������ �����Ѵ�. -> malloc
	ȸ�� ��ȣ�� ������ �Է��ϸ� �Է��� ����Ǹ�, �� ȸ�� ��, ��� ü��,
	�ְ� ü���� ���� ȸ����	������ ��µȴ�.

	1. ȸ�� ���� �Է�(��ȣ, �̸�, ü��)
	2. ���� �Է�
	3. �� ȸ�� ��, ��� ü��, �ְ� ü�� ȸ�� ��ȣ ���
	4. ���� �Ҵ� ��ȯ
*/
typedef struct {
	int num;
	char name[20];
	double weight;
}Fitness;
Fitness* ary[100];									// ������ �迭 ����
void total_number(int count);						// ��ü ��� ȸ�� �� ��ȯ
double average_weight(Fitness** pary, int count);	// ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);			// �ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index);			// ȸ�� ���� ���
void free_ary(Fitness** pary, int count);			// ���� �Ҵ� ���� ���� 


int main() {
	int i = 0;
	int num;
	char name[20];
	double weight;
	int max;
	while (i < 100) {

		printf("[%d] ȸ�� ��ȣ : ", i + 1);
		scanf_s("%d", &num);

		// ���� �Է½� ���� ��� �� ���α׷� ����
		if (num < 0) {
			// printf("ȸ�� �Է� ����!\n");
			total_number(i);
			printf("# ��� ü�� : %.2lf\n", average_weight(ary, i));
			max = max_weight(ary, i);
			print_info(ary, max);
			free_ary(ary, i);
			exit(0);
		}

		printf("[%d] �̸� �Է� : ", i + 1);
		scanf_s("%s", name, sizeof(name));
		strcat_s(name, sizeof(name), ""); // C6054 ���� ���� 
		printf("[%d] ü�� �Է� : ", i + 1);
		scanf_s("%lf", &weight);

		ary[i] = (Fitness*)malloc(sizeof(Fitness)); // ���� �Ҵ� 
		if (ary[i] != NULL) {
			ary[i]->num = num;
			strcpy_s(ary[i]->name, strlen(name) + 1, name);
			ary[i]->weight = weight;
		}
		i++;
	}

	return 0;
}

void total_number(int count) {
	printf("# �� ȸ�� �� : %d\n", count);
}

double average_weight(Fitness** pary, int count) { // ȸ�� ü�� ��� ��ȯ
	int sum = 0;
	double result;
	for (int i = 0; pary[i] != NULL; i++) {
		sum += pary[i]->weight;
	}
	result = sum / (double)count;
	return result;
}

int max_weight(Fitness** pary, int count) {
	int max = 0;
	double result;
	for (int i = 0; pary[i] != NULL; i++) {
		if (max < pary[i]->weight) max = i;
	}
	return max;
}

void print_info(Fitness** pary, int index) {
	printf("# ���� ü���� ���� ������ ȸ��\n");
	printf("> ȸ�� ��ȣ : %d\n", ary[index]->num);
	printf("> �̸� : %s\n", ary[index]->name);
	printf("> ü�� : %.1lf\n", ary[index]->weight);


}

void free_ary(Fitness** pary, int count) {
	for (int i = 0; pary[i] != NULL; i++) {
		free(pary[i]);
		pary[i] = NULL;
	}
}

