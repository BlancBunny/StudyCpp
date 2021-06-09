#include <iostream>
using namespace std;

class A {
public:
	A() {}
	~A() {}

	virtual void test() { printf("A::test()\n"); } // 가상 함수 (동적 바인딩) 
};

class B : public A {
public:
	B() {}
	~B() {}

	void test() { printf("B::test()\n"); }
	void test2() { printf("B::test2()\n"); }   // 정적 바인딩 함수 
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
		printf("잘못된 형변환\n");
	}
}

int main() {
	A* pac = new C;
	A* pab = new B;

	pac->test();
	B* pbc = dynamic_cast<B*>(pac); // C -> B 로 (down casting) 
	if (pbc) pbc->test2();

	C* pcc = dynamic_cast<C*>(pab); // B -> C 로 (up casting, 불완전) 
	if (pcc) pcc->test2();
	
	C c;
	globalFunc(c);
	B b;
	globalFunc(b);


	return 0;
}