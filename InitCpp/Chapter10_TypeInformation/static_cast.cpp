#include <stdio.h>
class Parent {};
class Child : public Parent {};

void func(Parent* p) {
	
}

int main() {
	Parent p, * pp;
	Child c, * pc;
	int i = 1234;
	double d = 123.456;
	int j;
	pp = static_cast<Parent*>(&c);
	pc = static_cast<Child*>(&c); // pc = &c;
	j = static_cast<int>(d);
	printf("%d", j);
} 
         
