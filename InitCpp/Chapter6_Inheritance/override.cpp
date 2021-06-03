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

	void intro() {
		Human::intro();
		printf("%d 학번 %s 입니다.\n", stunum, name);
	}
};

int main() {
	Human kim("김현수", 27);
	kim.intro();

	Student han("김한결", 21, 12345);
	han.intro();

	return 0;
}