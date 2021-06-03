#include <stdio.h> 

class Fahrenheit;
class Celsius
{
public:
	double tem;
	Celsius() { tem = 0; }
	Celsius(double tem) : tem(tem) {}
	// operator Fahrenheit();
	void OutTem() { printf("¼·¾¾ : %f\n", this->tem); }
};

class Fahrenheit {
public:
	double tem;
	Fahrenheit() { tem = 0; }
	Fahrenheit(double tem) : tem(tem) {}
	operator Celsius(); // º¯È¯ ÇÔ¼ö F -> C
	Fahrenheit(Celsius c) { // º¯È¯ »ı¼ºÀÚ C -> F 
		tem = c.tem * 1.8 + 32;
	}
	void OutTem() { printf("È­¾¾ : %f\n", this->tem); }
};

//Celsius::operator Fahrenheit() {
//	Fahrenheit f;
//	f.tem = tem * 1.8 + 32;
//	return f;
//}

Fahrenheit::operator Celsius() {
	Celsius c;
	c.tem = (tem - 32) / 1.8;
	return c;
}

int main() {
	Celsius c(100);
	Fahrenheit f(c);
	c.OutTem();
	f.OutTem();

	printf("\n");
	Fahrenheit f2 = 120;
	Celsius c2 = f2;
	f2.OutTem();
	c2.OutTem();

	return 0;
}