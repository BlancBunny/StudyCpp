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

	virtual void intro() {
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

	virtual void intro() {
		printf("�̸� : %s, �й� : %d\n", name, stunum);
	}

	virtual void study() {
		printf("Student method\n");
	}
};

int main() {
	Human h("����", 10);
	Student s("���л�", 15, 12345);
	Human* ph;

	ph = &h;
	ph->intro();
	ph = &s;
	ph->intro();
}