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
			puts("�޸� ����");
			break;
		case 2:
			puts("���� ���� �ʰ�");
			break;
		case 3:
			puts("�ϵ� ��ũ ��ȭ");
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
		puts("�۾� �Ϸ�");
	}
	catch (Exception& e) {
		printf("error code : %d => ", e.GetErrorCode());
		e.ReportError();
	}
}