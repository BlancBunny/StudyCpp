#include <iostream>
using namespace std;

class A {
public:
	A() {}
	~A() {}

	virtual void test() { printf("A::test()\n"); } // ���� �Լ� (���� ���ε�) 
};

class B : public A {
public:
	B() {}
	~B() {}

	void test() { printf("B::test()\n"); }
	void test2() { printf("B::test2()\n"); }   // ���� ���ε� �Լ� 
};

class C : public B {
public:
	C() {}
	~C() {}

	void test() { printf("C::test()\n"); }
	void test2() { printf("C::test2()\n"); }
};

void globalFunc(A& a) {
	try {
		C& c = dynamic_cast<C&>(a);
		printf("GlobalFunc()\n");
	}
	catch(bad_cast) {
		printf("�߸��� ����ȯ\n");
	}
}

int main() {
	A* pac = new C;
	A* pab = new B;

	pac->test();
	B* pbc = dynamic_cast<B*>(pac); // C -> B �� (down casting) 
	if (pbc) pbc->test2();

	C* pcc = dynamic_cast<C*>(pab); // B -> C �� (up casting, �ҿ���) 
	if (pcc) pcc->test2();
	
	C c;
	globalFunc(c);
	B b;
	globalFunc(b);


	return 0;
}