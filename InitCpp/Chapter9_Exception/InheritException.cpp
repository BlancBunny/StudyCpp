#include <stdio.h>

class ExNegative {
protected:
	int number;

public:
	ExNegative(int n) : number(n) {}
	virtual void PrintError() {	printf("%d는 음수\n", number); }
};

class ExTooBig : public ExNegative {
public:
	ExTooBig(int n) : ExNegative(n) {}
	virtual void PrintError() {
		printf("%d는 너무 큼\n", number);
	}
};

class ExOdd : public ExTooBig {
public:
	ExOdd(int n) : ExTooBig(n) {}
	virtual void PrintError() {
		printf("%d는 홀수\n", number);
	}
};

int main() {
	int n;

	for (;;) {
		try {
			printf("숫자 입력(끝낼 때 0) : ");
			scanf_s("%d", &n);
			if (n == 0) break;
			if (n < 0) throw ExNegative(n);
			if (n > 100) throw ExTooBig(n);
			if (n % 2 != 0) throw ExOdd(n);

			printf("%d rule correct!\n", n);
		}
		catch (ExNegative &e) {
			e.PrintError();
		}
	}
}