#include <stdio.h>
#include <exception>
using namespace std;

void myTerm() {
	puts("ó������ ���� ����");
	exit(-1);
}

int main() {
	set_terminate(myTerm); // ���� ���� �ڵ鷯
	try {
		throw 1;
	}
	catch (char* m) { // ���� ��ó�� ���� �ڵ鷯 

	}
}