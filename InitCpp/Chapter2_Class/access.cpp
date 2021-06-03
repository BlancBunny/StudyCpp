#include <stdio.h>

struct SHuman
{
private:
	char name[12];
	int age;

public:
	void intro() {
		printf("이름 : %s, 나이 : %d", name, age);
	}
	int getAge() { return age; }
	void setAge(int aAge) {
		if (aAge > 0 && aAge < 120) {
			age = aAge;
		}
	}

};

int main() {
	SHuman kim;
	kim.setAge(20);
	kim.intro();
}