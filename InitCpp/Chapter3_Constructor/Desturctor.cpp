#include <stdio.h>
#include <string.h>

class Human {
private:
	char* pname;
	int age;

public:
	Human(const char* name, int age) {
		pname = new char[strlen(name) + 1];
		strcpy_s(pname, strlen(name)+1, name);
		this->age = age;
		printf("생성자 호출\n");
	}

	~Human() {
		printf("파괴자 호출\n");
		delete[] pname;
	}
	
	void intro() {
		printf("이름 : %s, 나이 : %d\n", this->pname, this->age);	
	}
};

int main() {
	Human boy("김수한무", 12);
	boy.intro();
	return 0;
}