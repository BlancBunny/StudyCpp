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
protected:
	int stunum;

public:
	Student(const char* name, int age, int stunum) : Human(name, age) {
		this->stunum = stunum;
	}

	void intro() {
		Human::intro();
		printf("%d �й� %s �Դϴ�.\n", stunum, name);
	}
};

int main() {
	Human kim("������", 27);
	kim.intro();

	Student han("���Ѱ�", 21, 12345);
	han.intro();

	return 0;
}