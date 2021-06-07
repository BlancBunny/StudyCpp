#include <iostream>
#include "../cursor.h"
using namespace std;

template <typename T>
class PosValue {
private:
	int x, y;
	T value; 

public:
	PosValue(int x, int y, T v) : x(x), y(y), value(v) { }
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

int main() {
	PosValue<int> iv(10, 10, 2);
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);
	iv.outvalue();
	cv.outvalue();
	dv.outvalue();
}
