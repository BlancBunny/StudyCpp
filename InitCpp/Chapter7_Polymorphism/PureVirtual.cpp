#include <stdio.h>

// 추상 클래스 : 순수 가상 함수(=0)를 포함하는 클래스 
// 이 클래스를 상속하는 클래스는 반드시 해당 함수를 재정의 해야함 
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



