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
		printf("�̸� : %s, ���� : %d", name, age);
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
		printf("�̸� : %s, �й� : %d\n", name, stunum);
	}
	void study() {
		printf("student method\n");
	}
};

int main() {
	Human h("����", 10);
	Student s("���л�", 15, 12345);
	Human* ph = new Student("�̸�", 3, 12345);
	Student* ps;
	
	Student* newS = (Student *)ph;
	newS->intro();

	ph = &h;
	ps = &s;
	ph = &s;  // ����
	// ps = &h : ���� 

	ps = (Student *)&h;
// 	ps->intro();

}