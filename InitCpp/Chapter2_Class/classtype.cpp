#include <stdio.h>

class Human {
public:
	char name[12];
	int age;

	void intro() {
		printf("捞抚 : %s, 唱捞 : %d\n", this->name, this->age);
	}

	void setAge(int age) {
		this->age = age;
	}
};

int main() {
	Human arFriend[10] = {
		{"模备1", 27},
		{"模备2", 27},
		{"模备3", 27},
	};

	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->setAge(28);
	pFriend->intro();

	return 0;
}