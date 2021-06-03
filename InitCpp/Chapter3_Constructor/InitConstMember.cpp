#include <stdio.h>

class Some {
public:
	const int total;
	Some(int total) : total(total) { }
	void OutTotal() { printf("%d\n", total); }
};

int main() {
	Some s(5);
	s.OutTotal();
	return 0;
}