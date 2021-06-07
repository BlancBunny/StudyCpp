#include <stdio.h>

class Base {
private:
	char* B_buf;
public:
	Base() { B_buf = new char[10]; puts("Base 생성"); }
	virtual ~Base() { delete[] B_buf; puts("Base 파괴"); }
};

class Derived : public Base {
private:
	int* D_buf; 
public:
	Derived() { D_buf = new int[32]; puts("Derived 생성"); }
	virtual ~Derived() { delete[] D_buf; puts("Derived 파괴"); }
};

int main() {
	// Derived d; -> 문제 없음 
	Base* pB = new Derived; 
	delete pB;
	/* pB는 Base 형이므로 Derived 파괴자를 불러오지 않는다.
	따라서 Derived 생성자 호출시 만들어진 D_buf 속성이 
	해제되지 않아 메모리 누수 발생 */

	return 0;
}
