#include <stdio.h>
#include <exception>
using namespace std;

void myTerm() {
	puts("처리되지 않은 예외");
	exit(-1);
}

int main() {
	set_terminate(myTerm); // 전역 예외 핸들러
	try {
		throw 1;
	}
	catch (char* m) { // 지역 미처리 예외 핸들러 

	}
}