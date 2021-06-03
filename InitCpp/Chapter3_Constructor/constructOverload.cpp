#include <stdio.h>

class Time {
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		this->hour = h;
		this->min = m;
		this->sec = s;
	}

	Time(int abssec) {
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	void OutTime() {
			printf("현재 시간은 %d:%d:%d입니다.\n", this->hour, this->min, this->sec);
	}
	
};

int main() {
	Time now(12, 30, 40);
	now.OutTime();
	Time noon(45040);
	noon.OutTime();
}