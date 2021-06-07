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

	void eat() {
		puts("³È³È³È");
	}

	virtual void intro() {
		printf("ÀÌ¸§ : %s, ³ªÀÌ = %d\n", name, age);
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
		printf("ÀÌ¸§ : %s, ÇĞ¹ø : %d\n", name, stunum);
	}
};

int main() {
	Human h("±è»ç¶÷", 10);
	Student s("ÀÌÇĞ»ı", 15, 12345);
	Human* ph;

	ph = &h;
	ph->intro();
	ph->eat();

	ph = &s;
	ph->intro();
	ph->eat();

	return 0;
}