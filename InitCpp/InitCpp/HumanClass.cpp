/*
	HumanClass.cpp
	Human class 생성
	char *name
	int age 
	printHuman() 
*/

#include <stdio.h>
#include <string.h>

class Human {
private:
	char* name;
	int age;

public:
	Human() { name = 0; age = 0; }
	Human(const char* name, int age) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
		printf("%s : 생성자 호출\n", this->name);
	}
	Human(const Human& other) {
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		this->age = other.age;
		printf("%s : 복사 생성자 호출\n", this->name);
	}

	const Human& operator =(const Human& other) {
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		this->age = other.age;
		printf("%s : 대입 연산자\n", this->name);
		return *this;
	}

	~Human() {
		printf("%s : 소멸자 호출\n", this->name);
		delete[] this->name;
	}

	void PrintHuman() {
		printf("이름 : %s, 나이 : %d\n", this->name, this->age);
	}
};

int main() {
	// step 1. 생성자/소멸자 
	Human hong("홍길동", 380);
	hong.PrintHuman();

	/*
	Human* kim = new Human("김현수", 27);
	kim->PrintHuman();
	delete kim;
	*/

	// step 2. 복사 생성자 
	Human youH("아무개", 20);
	Human myH(youH);
	myH.PrintHuman();

	// step 3. 연산자 오버로딩
	Human xMan;
	xMan = myH;
	xMan.PrintHuman();

	return 0;
}