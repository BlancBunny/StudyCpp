#include <stdio.h>

class Time {
private:
	int hour, min, sec;

public:
	Time() { hour = 0; min = 0; sec = 0; }
	Time(int h, int m, int s) {
		hour = h; min = m; sec = s;
	}
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}

	const Time operator *(int s) const {
		Time t = *this;

		t.hour *= s;
		t.min *= s;
		t.sec *= s;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t;
	}
};

const Time operator *(int s, const Time& me) {
	return (me * s);
}

int main() {
	Time t(1, 20, 12);
	t.OutTime();
	t = t * 2;
	t.OutTime();
	t = 3 * t;
	t.OutTime();
	return 0;
}

