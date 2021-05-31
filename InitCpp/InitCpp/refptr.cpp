#include <string.h>
#include <iostream>

using namespace std;

void InputName(char*& Name) {
	Name = (char*)malloc(32);
	strcpy_s(Name, 15, "Kim hyun su");
}

int main() {
	/*char* Name;
	InputName(Name);

	printf("이름은 %s입니다.\n", Name);
	free(Name);*/

	int a = 10;
	int& ra = a;
	int* pa = &ra;
	printf("%p %p %p", &a, &ra, pa);

	return 0;
}