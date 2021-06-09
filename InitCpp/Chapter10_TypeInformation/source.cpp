#include <stdio.h>

class Super {
private:
	int data;

public:
	Super() { data = 0; }
	~Super() {}
	void setData(int data) {
		this->data = data;
	}
	int getData() {
		return this->data;
	}
};

class Sub : public Super {
private:
	int data2;
public:
	Sub() { data2 = 0; }
	~Sub() {}
	void setData2(int data2) {
		this->data2 = data2;
	}
	int getData2() {
		return this->data2;
	}
	void printData() {
		printf("printData() : %d\n", getData());
	}
};

int main() {
	Super* ps = new Sub; 
	Sub* pb = NULL;

	ps->setData(10);
	// pb->setData2(30);
	pb = static_cast<Sub*>(ps);
	pb->printData();
	pb->setData2(30);
	printf("%d", pb->getData2());

	
	return 0;
}