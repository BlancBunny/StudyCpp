#include <stdio.h>
#include <string.h>

class Human {
private:
	char* name;
public:
	Human() { name = 0; };
	Human(const char* name) {
		int len = strlen(name) + 1;
		this->name = new char[len];
		if (this->name != NULL) strcpy_s(this->name, len, name);
	}
	~Human() {
		delete[] this->name;
	}

	void PrintName() {
		printf("My name is %s\n", this->name);
	}
};

class Student : public Human {
private:
	char* major;
public:
	Student() { major = 0; }
	Student(const char* name, const char* major) : Human(name) {
		int len = strlen(major) + 1;
		this->major = new char[len];
		if (this->major != NULL) strcpy_s(this->major, len, major);
	}
	~Student() {
		delete[] this->major;
	}
	void PrintMajor() {
		PrintName();
		printf("major - %s\n", major);
	}
	
};

int main() {
	Human my("홍길동");
	my.PrintName();
	Student s("김현수", "IoT");
	s.PrintMajor(); // My name is 이름, major - 전공
	return 0;
}