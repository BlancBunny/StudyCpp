#include <stdio.h>

class Exception {
private:
	int errorCode;
public:
	Exception(int e) : errorCode(e) {}
	int GetErrorCode() { return errorCode; }
	void ReportError() {
		switch (errorCode) {
		case 1:
			puts("메모리 부족");
			break;
		case 2:
			puts("연산 범위 초과");
			break;
		case 3:
			puts("하드 디스크 포화");
			break;
		}
		
	}
};

void report() {
	if (true) throw Exception(3);
}

int main() {
	try {
		report();
		puts("작업 완료");
	}
	catch (Exception& e) {
		printf("error code : %d => ", e.GetErrorCode());
		e.ReportError();
	}
}