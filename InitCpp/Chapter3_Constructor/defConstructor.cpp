#include <stdio.h>
#include <string.h>

class Human {
private:
	char name[12];
	int age;

public:
	Human() {
		strcpy_s(name, 12, "�̸�����");
		age = 0;
	}
	void intro() {
		printf("�̸� : %s, ���� : %d\n", this->name, this->age);
	}
};

int main() {
	Human momo;
	momo.intro();

	return 0;
}
