#include <stdio.h>

class Shape {
public:
	virtual void draw() { printf("Shape Object\n"); } // Method Dynamic Binding 
};

class Line : public Shape {
public:
	void draw() { printf("Draw Line Method!\n"); }
};

class Circle : public Shape {
public:
	void draw() { printf("Draw Circle Method!\n"); }
};

class Rect : public Shape {
public:
	void draw() { printf("Draw Rectangle Method!\n"); }
};

int main() {
	Shape* ar[] = { new Shape(), new Line(), new Circle(), new Rect() };
	
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
	{
		ar[i]->draw();
	}
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
		delete ar[i];
	}
}