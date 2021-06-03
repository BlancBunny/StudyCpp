#include <stdio.h>
#include <string.h>
class Human {
protected:
	char name[12];
	int age;

public:
	Human(const char* name, int age) {
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}

	void intro() {
		printf("�̸� : %s, ���� : %d\n", name, age);
	}
};

class Student : public Human {
private:
	int stunum;

public:
	Student(const char* name, int age, int stunum) : Human(name, age) {
		this->stunum = stunum;
	}
	void study() {
		printf("%s's student number : %d\n", name, stunum);
	}
};

int main() {
	Human kim("������", 27);
	kim.intro();
	Student han("���Ѱ�", 15, 123456);
	han.intro();
	han.study();
}