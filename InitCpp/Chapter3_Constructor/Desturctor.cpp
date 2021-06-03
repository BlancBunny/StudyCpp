#include <stdio.h>
#include <string.h>

class Human {
private:
	char* pname;
	int age;

public:
	Human(const char* name, int age) {
		pname = new char[strlen(name) + 1];
		strcpy_s(pname, strlen(name)+1, name);
		this->age = age;
		printf("������ ȣ��\n");
	}

	~Human() {
		printf("�ı��� ȣ��\n");
		delete[] pname;
	}
	
	void intro() {
		printf("�̸� : %s, ���� : %d\n", this->pname, this->age);	
	}
};

int main() {
	Human boy("����ѹ�", 12);
	boy.intro();
	return 0;
}