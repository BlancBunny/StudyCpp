#include <stdio.h>
#include <malloc.h>
#include <memory.h>

template <class T>
void swaparray(T* a, T* b, int num) {
	int size = num * sizeof(T);
	void* t = malloc(size);
	if (t != NULL) {
		memcpy(t, a, size);
		memcpy(a, b, size);
		memcpy(b, t, size);
	}
	free(t);
}

int main() {
	int a[] = { 1,2,3 }, b[] = { 4,5,6 };
	char c[] = "¹®ÀÚ¿­", d[] = "string";
	swaparray(a, b, sizeof(a) / sizeof(a[0]));
	
	printf("before c : %s, d : %s\n", c, d);
	swaparray(c, d, sizeof(c) / sizeof(c[0]));
	printf("after c : %s, d : %s\n", c, d);
	return 0;
}