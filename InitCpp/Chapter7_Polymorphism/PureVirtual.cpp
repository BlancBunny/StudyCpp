#include <stdio.h>

// �߻� Ŭ���� : ���� ���� �Լ�(=0)�� �����ϴ� Ŭ���� 
// �� Ŭ������ ����ϴ� Ŭ������ �ݵ�� �ش� �Լ��� ������ �ؾ��� 
class Shape { 
public:
	virtual void draw() = 0;
};

class Line : public Shape {
public:
	void draw() { puts("Draw Line Method"); }
};

class Circle : public Shape {
public:
	void draw() { puts("Draw Circle Method"); }
};

class Rect : public Shape {
public:
	void draw() { puts("Draw Rectangle Method"); }
};


int main() {
	Shape* ps[3] = { new Line, new Circle, new Rect };

	for (int i = 0; i < 3; i++) {
		ps[i]->draw();
	}

	for (int i = 0; i < 3; i++) {
		delete ps[i];
	}

}



