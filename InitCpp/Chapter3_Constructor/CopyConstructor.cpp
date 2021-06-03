#include <stdio.h>
#include <string.h>

class Human {
private:
	char* pname;
	int age;

public:
	Human(const char* name, int age) {
		this->pname = new char[strlen(name) + 1];
		strcpy_s(this->pname, strlen(name) + 1, name);
		this->age = age;
	}

	Human(const Human& other) {
		this->pname = new char[strlen(other.pname) + 1];
		strcpy_s(this->pname, strlen(other.pname) + 1, other.pname);
		this->age = other.age;
	}

	~Human() {
		delete[] pname;
	}

	void intro() {
		printf("이름 : %s, 나이 : %d\n", this->pname, this->age);
	}
};

void printHuman(Human who) {
	who.intro();
}

int main() {
	Human kang("강감찬", 1424);
	Human boy = kang;

	printHuman(boy);
	return 0;
}
