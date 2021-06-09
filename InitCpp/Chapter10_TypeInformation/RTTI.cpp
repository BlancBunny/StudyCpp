#include <stdio.h>

class Parent {
public:
	virtual void PrintMe() { printf("I am Parent\n"); }
};

class Child : public Parent {
private:
	int num;
public:
	Child(int num) : num(num) {}
	virtual void PrintMe() { printf("I am child\n"); }
	void PrintNum() { printf("Hello Child = %d\n", num); }
};

void func(Parent* p) {
	p->PrintMe();
	((Child*)p)->PrintNum();
}

int main() {
	Parent p;
	Child c(5);

	func(&c);
	func(&p);

	return 0;
}