#include <stdio.h>

int report() {
	if (true) return 1;

	//

	return 0;
}

int main() {
	int e;
	e = report();
	switch (e) {
	case 1:
		puts("메모리가 부족합니다.");
		break;
	case 2:
		puts("연산 범위 초과");
		break;
	case 3:
		puts("하드 디스크 포화");
		break;
	default:
		puts("작업 완료");
		break;
	}
}
