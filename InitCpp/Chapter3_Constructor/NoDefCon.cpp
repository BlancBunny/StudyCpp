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
		printf("捞抚 : %s, 唱捞 : %d\n", this->name, this->age);
	}
};

int main() {
	Human arFriend[3] = {
		{Human("模备1", 32)},
		{Human("模备2", 33)},
		{Human("模备3", 34)}
	};

	arFriend[2].intro();


	return 0;
}