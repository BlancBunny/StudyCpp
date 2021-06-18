#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1("abc");
	string s2;

	s2 = "random string";
	cout << s2 << endl;
	s2 = s1;
	cout << s2 << endl;
	s2 = 'A';
	cout << s2 << endl;

	s1 += "문자열 연결";
	cout << s1 << endl;
	s1 += s2;
	cout << s1 << endl;
	s1 += '!';
	cout << s2 << endl;

	string s3;
	s3 = "s1 : " + s1 + "s2 : " + s2 + '.';
	cout << s3 << endl;
	
	return 0;
}