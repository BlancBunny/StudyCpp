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
		printf("이름 : %s, 나이 : %d", name, age);
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
		printf("이름 : %s, 학번 : %d\n", name, stunum);
	}
	void study() {
		printf("student method\n");
	}
};

int main() {
	Human h("김사람", 10);
	Student s("이학생", 15, 12345);
	Human* ph = new Student("이름", 3, 12345);
	Student* ps;
	
	Student* newS = (Student *)ph;
	newS->intro();

	ph = &h;
	ps = &s;
	ph = &s;  // 가능
	// ps = &h : 에러 

	ps = (Student *)&h;
// 	ps->intro();

}