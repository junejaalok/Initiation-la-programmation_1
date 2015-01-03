#include <iostream>
#include <string>
using namespace std;

char decale (char c, char debut, int decalage) {

	while (decalage < 0) decalage+=26;
	if (c>='a' && c <= 'z') debut='a';
	else if (c>='A' && c <= 'Z') debut='A';
	else return c;

	return char(debut + (((c - debut) + decalage) % 26));
}

char code(char c, int d) {
	decale (c, 'a', d);
}

string code (string str, int d) {
	string temp;
	for (int i=0;i<str.length();i++) {
		temp+=(code(str[i],d));
	}
	return temp;
}

string decode (string str, int d) {
	string temp;
	d*=-1;
	for (int i=0;i<str.length();i++) {
		temp+=(code(str[i],d));
	}
	return temp;
}



int main()
{
	cout << decale('g', 'a', -133) << endl;
//	cout << code("Fuyez manants",4) << endl;
//	cout << decode("Jycid qererxw",4) << endl;
	return 0;
}