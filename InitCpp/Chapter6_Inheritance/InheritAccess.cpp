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

	void study() {
		printf("보고서123\n");
	}

	void report() {
		printf("이름 : %s, 학번 : %d 보고서 제출합니다\n", name, stunum);
	}

};


int main() {
	Student han("김한결", 16, 123456);
	han.intro();
	han.study();
	han.report();

	return 0;
}