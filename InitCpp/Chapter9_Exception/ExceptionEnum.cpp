#include <stdio.h>

enum E_Error {OUTOFMEMORY, OVERRANGE, HARDFULL};
void report() throw(E_Error) {
	if (true) throw OVERRANGE;

}

int main() {
	try {
		report();
		puts("작업 완료");
	}
	catch (E_Error e) {
		switch (e) {
		case OUTOFMEMORY:
			puts("메모리 부족");
			break;
		case OVERRANGE:
			puts("연산 범위 초과");
			break;
		case HARDFULL:
			puts("하드 디스크 포화");
			break;
		}
	}
}