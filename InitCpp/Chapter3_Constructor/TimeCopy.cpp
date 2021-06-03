#include <stdio.h>

class Time {
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() {
		printf("½Ã°£ : %d:%d:%d\n", hour, min, sec);
	}
};

int main() {
	Time now(12, 34, 56);
	Time then = now;
	then.OutTime();
}