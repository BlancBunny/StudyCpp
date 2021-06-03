#include <stdio.h>
#include <string.h>

class Human {
private:
	char name[12];
	int age;

public:
	Human(const char* name, int age) {
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}
	void intro() {
		printf("�̸� : %s, ���� : %d\n", this->name, this->age);
	}
};

int main() {
	Human arFriend[3] = {
		{Human("ģ��1", 32)},
		{Human("ģ��2", 33)},
		{Human("ģ��3", 34)}
	};

	arFriend[2].intro();


	return 0;
}