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
		printf("이름 : %s, 나이 : %d\n", name, age);
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
		printf("이름 : %s, 학번 : %d\n", name, stunum);
	}

	virtual void study() {
		printf("Student method\n");
	}
};

int main() {
	Human h("김사람", 10);
	Student s("이학생", 15, 12345);
	Human* ph;

	ph = &h;
	ph->intro();
	ph = &s;
	ph->intro();
}