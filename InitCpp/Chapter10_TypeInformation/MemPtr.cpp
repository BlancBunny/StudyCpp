#include <stdio.h>

class Calc {
public:
	void Op1(int a, int b) { printf("%d\n", a + b); }
	void Op2(int a, int b) { printf("%d\n", a - b); }
	void Op3(int a, int b) { printf("%d\n", a * b); }
	void DoCalc(void (Calc::* fp)(int, int), int a, int b) {
		(this->*fp)(a, b);
	}
};

int main() {
	int ch;
	Calc c;
	int a = 3, b = 4;
	void (Calc:: * arop[3])(int, int) = { &Calc::Op1, &Calc::Op2, &Calc::Op3 };
	printf("연산 방법 선택 [0(+), 1(-), 2(*)] : ");
	scanf_s("%d", &ch);
	
	if (ch >= 0 && ch <= 2) {
		// (c.*arop[ch])(3, 4);
		c.DoCalc(arop[ch], a, b);
	}
}
