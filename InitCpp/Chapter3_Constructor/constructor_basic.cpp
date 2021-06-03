#include <iostream>

class Ctest {
private:
	int num;
public:
	Ctest() { 
		num = 0; 
		printf("생성자 호출 : %d\n", this->num);
	}
	Ctest(int num) {
		this->num = num;
		printf("생성자 호출 : %d\n", this->num);
	}

	/*Ctest(const Ctest other) {
		this->num = other.num;
		printf("생성자 호출 : %d\n", this->num);
	}*/

	void getData() {
		printf("%d\n", this->num);
	}

	~Ctest() {
		printf("소멸자 호출 : %d\n", this->num);
	}
};

int main() {

	int a = 10;
	int b(20);
	printf("a : %d, b : %d\n", a, b);

	Ctest c1, c2(100);
	Ctest c3 = c2;

	
	return 0;
}