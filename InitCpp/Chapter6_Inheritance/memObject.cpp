#include <stdio.h>
#include <string.h>

class Date {
protected:
	int year, month, day;
public:
	Date() { year = 0; month = 0; day = 0; }
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
	}
	void OutDate() {
		printf("%d/%d/%d\n", year, month, day);
	}
};

class Product : private Date {
private:
	char name[64];
	char company[32];
	Date validto;
	int price;
public:
	Product(const char* name, const char* company, int y, int m, int d, int price) : validto(y, m, d) {
			strcpy_s(this->name, strlen(name) + 1, name);
			strcpy_s(this->company, strlen(company) + 1, company);
			this->price = price;
		}
	
	void OutProduct() {
		printf("이름 : %s\n", name);
		printf("제조사 : %s\n", company);
		printf("유효기간 : ");
		validto.OutDate();
		printf("가격 : %d\n", price);
	}
};

int main() {
	Product shrimp("새우깡", "농심", 2020, 8, 15, 900);
	shrimp.OutProduct();
	return 0;
}