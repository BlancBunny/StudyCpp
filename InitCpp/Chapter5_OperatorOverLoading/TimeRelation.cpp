#include <stdio.h>

class Time {
private:
	int hour, min, sec;

public:
	Time() {} 
	Time(int h, int m, int s) {	hour = h; min = m; sec = s; }

	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
	bool operator ==(const Time& other) const {
		return (hour == other.hour && min == other.min && sec == other.sec);
	}
	bool operator !=(const Time& other) const {
		return !(*this == other);
	}

	bool operator >(const Time& other) const {
		if (hour > other.hour) return true;
		if (hour < other.hour) return false;
		if (min > other.min) return true;
		if (min < other.min) return false;
		if (sec > other.sec) return true;
		if (sec < other.sec) return false;
		return false;
	}

	bool operator >= (const Time& other) const {
		return (*this == other) || (*this > other);
	}

	bool operator < (const Time& other) const {
		return !(*this >= other);
	}

	bool operator <= (const Time& other) const {
		return !(*this > other);
	}
}; 


int main() {
	Time t1(12, 34, 56);
	Time t2(12, 34, 56);
	printf("t1 : "); t1.OutTime();
	printf("t2 : "); t2.OutTime();
	if (t1 == t2) printf("==\n");
	else printf("!=\n");

	if (t1 > t2) printf("t1 > t2\n");
	else printf("t1 <= t2\n");
	
}