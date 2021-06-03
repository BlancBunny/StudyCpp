#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	실기 : 휘트니스 회원관리 프로그램
	신규회원 등록은 회원 번호와 이름, 체중을 입력하고, heap 영역에 저장한다. -> malloc
	회원 번호로 음수를 입력하면 입력이 종료되며, 총 회원 수, 평균 체중,
	최고 체중을 갖는 회원의	정보가 출력된다.

	1. 회원 정보 입력(번호, 이름, 체중)
	2. 음수 입력
	3. 총 회원 수, 평균 체중, 최고 체중 회원 번호 출력
	4. 동적 할당 반환
*/
typedef struct {
	int num;
	char name[20];
	double weight;
}Fitness;
Fitness* ary[100];									// 포인터 배열 선언
void total_number(int count);						// 전체 등록 회원 수 반환
double average_weight(Fitness** pary, int count);	// 평균 체중 반환
int max_weight(Fitness** pary, int count);			// 최대 체중 회원의 index 반환
void print_info(Fitness** pary, int index);			// 회원 정보 출력
void free_ary(Fitness** pary, int count);			// 동적 할당 영역 해제 


int main() {
	int i = 0;
	int num;
	char name[20];
	double weight;
	int max;
	while (i < 100) {

		printf("[%d] 회원 번호 : ", i + 1);
		scanf_s("%d", &num);

		// 음수 입력시 정보 출력 및 프로그램 종료
		if (num < 0) {
			// printf("회원 입력 종료!\n");
			total_number(i);
			printf("# 평균 체중 : %.2lf\n", average_weight(ary, i));
			max = max_weight(ary, i);
			print_info(ary, max);
			free_ary(ary, i);
			exit(0);
		}

		printf("[%d] 이름 입력 : ", i + 1);
		scanf_s("%s", name, sizeof(name));
		strcat_s(name, sizeof(name), ""); // C6054 오류 방지 
		printf("[%d] 체중 입력 : ", i + 1);
		scanf_s("%lf", &weight);

		ary[i] = (Fitness*)malloc(sizeof(Fitness)); // 동적 할당 
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
	printf("# 총 회원 수 : %d\n", count);
}

double average_weight(Fitness** pary, int count) { // 회원 체중 평균 반환
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
	printf("# 가장 체중이 많이 나가는 회원\n");
	printf("> 회원 번호 : %d\n", ary[index]->num);
	printf("> 이름 : %s\n", ary[index]->name);
	printf("> 체중 : %.1lf\n", ary[index]->weight);


}

void free_ary(Fitness** pary, int count) {
	for (int i = 0; pary[i] != NULL; i++) {
		free(pary[i]);
		pary[i] = NULL;
	}
}

