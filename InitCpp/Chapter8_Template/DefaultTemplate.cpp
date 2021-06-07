#include <iostream>
using namespace std;

template <typename T = int, int size = 3>

class CTest {
private:
	T ary[size];
public:
	T& operator[] (int idx) {
		if (idx < 0 || idx >= size) {
			cout << "error" << endl;
			exit(1);
		}
		return ary[idx];
	}
	void getData() {
		for (int i = 0; i < size; i++) {
			cout << ary[i] << endl;
		}
	}
};

int main() {
	
	int a[5];
	a[0] = 1;

	CTest<> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	
	arr.getData();

	return 0;
}