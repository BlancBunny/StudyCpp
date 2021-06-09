#include <stdio.h>
#include <string.h>

class Parent {
public:
	char classname[32];
	Parent() {
		strcpy_s(classname, 7, "Parent");
	}
	virtual void PrintMe() {
		printf("I am Parent\n");
	}
};

class Child : public Parent {
private:
	int num;

public:
	Child(int num) : num(num) {
		strcpy_s(classname, 6, "Child");
	}
	virtual void PrintMe() { printf("I am Child\n"); }
	void PrintNum() { printf("Hello Child = %d\n", num); }
};

void func(Parent* p) {
	p->PrintMe();
	if (strcmp(p->classname, "Child") == 0) {
		((Child*)p)->PrintNum();
	}
	else {
		puts("이 객체는 num을 가지고 있지 않음");
	}
}

int main() {
	Parent p;
	Child c(5);

	func(&c);
	func(&p);

	return 0;
}

