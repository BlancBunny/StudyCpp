#include <stdio.h>

class Human {
public:
	char name[12];
	int age;

	void intro() {
		printf("�̸� : %s, ���� : %d\n", this->name, this->age);
	}

	void setAge(int age) {
		this->age = age;
	}
};

int main() {
	Human arFriend[10] = {
		{"ģ��1", 27},
		{"ģ��2", 27},
		{"ģ��3", 27},
	};

	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->setAge(28);
	pFriend->intro();

	return 0;
}