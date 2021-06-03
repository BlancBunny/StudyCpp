#include <stdio.h>

struct SHuman
{
public:
	char name[12];
	int age;
	float height;
	float weight;
	char blood;

	void view();
};

void SHuman::view() {
	printf("%s, %d, %.1f, %.1f, %c", name, age, height, weight, blood);
}

int main() {
	SHuman sh = { "ȫ�浿", 24, 165.5, 57.0, 'A' };
	sh.view();
}