#include <stdio.h>
#include <string.h>

class Product {
private:
	char name[64];
	char company[32];
	int price;

	
	
public:
	class Date {
	protected:
		int year, month, day;
	public:
		Date(int y, int m, int d) {
			year = y; month = m; day = d;
		}
		void OutDate() {
			printf("%d/%d/%d\n", year, month, day);
		}

	};
	Date validto;
	Product(const char* name, const char* company, int y, int m, int d, int price) : validto(y, m, d) {
		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->company, strlen(company) + 1, company);
		this->price = price;
	}
	void OutProduct() {
		printf("�̸� : %s\n", name);
		printf("������ : %s\n", company);
		printf("��ȿ�Ⱓ : ");
		validto.OutDate();
		printf("���� : %d\n", price);
	}
};


int main() {
	Product shrimp("�����", "���", 2020, 8, 15, 800);
	shrimp.OutProduct();

	Product::Date now(12, 34, 56);
	now.OutDate();
}