#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "../InitCpp/cursor.h"

class Point {
protected:
	int x, y;
	char ch;

public:
	Point(int x, int y, char ch) { this->x = x; this->y = y; this->ch = ch; }
	virtual void show() {
		gotoxy(x, y); _putch(ch);
	}
	virtual void hide() { gotoxy(x, y); _putch(' '); }
	void move(int x, int y) {
		hide();
		this->x = x;
		this->y = y;
		show();
	}
};

class Circle : public Point {
protected:
	int radius;

public:
	Circle(int x, int y, int ch, int rad) : Point(x, y, ch) {
		this->radius = rad;
	}
	void show() {
		for (double a = 0; a < 360; a += 10) {
			gotoxy(int(x + sin(a * 3.14 / 180) * radius), int(y - cos(a * 3.14 / 180) * radius / 2));
			_putch(ch);
		}
	}
	void hide() {
		for (double a = 0; a < 360; a += 10) {
			gotoxy(int(x + sin(a * 3.14 / 180) * radius), int(y - cos(a * 3.14 / 180) * radius / 2));
			_putch(' ');
		}
	}
	void move(int x, int y) {
		hide();
		this->x = x;
		this->y = y;
		show();
	}
};

int main() {
	Point p(1, 1, 'P');
	Circle c(20, 20, 'C', 12);

	p.show();
	c.show();

	_getch();
	p.move(40, 1);
	_getch();
	c.move(40, 20);
	_getch();

	return 0;
}