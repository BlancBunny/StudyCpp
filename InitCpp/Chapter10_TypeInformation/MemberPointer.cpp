#include <stdio.h>

class MyClass {
public:
	MyClass() { i = 0; j = 0; d = 0; }
	int i, j;
	double d;
};

int main() {
	MyClass C;
	int MyClass::* pi;
	double MyClass::* pd;
	int num;

	pi = &MyClass::i;
	pi = &MyClass::j;
	pd = &MyClass::d;

	C.*pi;


}