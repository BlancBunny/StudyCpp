#include <stdio.h>

class Time {
	int hour, min, sec;

public:
	void SetTime(int h, int m, int s) {
		this->hour = h;
		this->min = m;
		this->sec = s;
	}
	void OutTime() {
		printf("���� �ð��� %d:%d:%d �Դϴ�\n", this->hour, this->min, this->sec);
	}
};

class Date {
private:
	int year, month, date;

public:
	void SetDate(int y, int m, int d) {
		this->year = y;
		this->month = m;
		this->date = d;
	}

	void OutDate() {
		printf("������ %d�� %d�� %d���Դϴ�.\n", this->year, this->month, this->date);
	}

};

int main() {
	Time now;
	Date date;
	now.SetTime(12, 30, 40);
	now.OutTime();
	date.SetDate(2021, 5, 31);
	date.OutDate();

	return 0;
}