/*
	HumanClass.cpp
	Human class ����
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
		printf("%s : ������ ȣ��\n", this->name);
	}
	Human(const Human& other) {
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		this->age = other.age;
		printf("%s : ���� ������ ȣ��\n", this->name);
	}

	const Human& operator =(const Human& other) {
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		this->age = other.age;
		printf("%s : ���� ������\n", this->name);
		return *this;
	}

	~Human() {
		printf("%s : �Ҹ��� ȣ��\n", this->name);
		delete[] this->name;
	}

	void PrintHuman() {
		printf("�̸� : %s, ���� : %d\n", this->name, this->age);
	}
};

int main() {
	// step 1. ������/�Ҹ��� 
	Human hong("ȫ�浿", 380);
	hong.PrintHuman();

	/*
	Human* kim = new Human("������", 27);
	kim->PrintHuman();
	delete kim;
	*/

	// step 2. ���� ������ 
	Human youH("�ƹ���", 20);
	Human myH(youH);
	myH.PrintHuman();

	// step 3. ������ �����ε�
	Human xMan;
	xMan = myH;
	xMan.PrintHuman();

	return 0;
}