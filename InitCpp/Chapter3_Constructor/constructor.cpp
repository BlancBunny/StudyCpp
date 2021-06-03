#include <stdio.h>
#include <string.h>
#define _SIZE 12

class Human {
private:
	char name[_SIZE];
	int age;

public:
	Human(const char* name, int age) {
		strcpy_s(this->name, _SIZE, name);
		this->age = age;
	}
	
	void intro() {
		printf("�̸� : %s, ���� : %d", this->name, this->age);
	}
};

int main() {
	Human kim("������", 27);
	kim.intro();
}