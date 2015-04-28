#include <iostream>
#include <string>
using namespace std;


char convert(int i) {
	if (i==1) return '1';
	else return '0';
}

string Z0(int n) {
	string res="";
	int last;
	do {
		last=n%2;
		res=convert(last)+res;
		n/=2;
	} while (n!=0);
	return res;
}

string Z0t(int n) {
	string temp="";
	if (n==1) return temp;
	else {
		temp=Z0(n);
		temp=temp.erase(0,1);
		return temp;
	}
}

string Z1(int n) {
	string temp;
	temp=Z0(n);
	int len=temp.length()-1;
	temp=string(len,'0').append(temp);
	return temp;
}

string Z2(int n) {
	string res="";
	int len=Z0(n).length();
	res=res+Z1(len)+Z0t(n);
	return res;
}

int main() {
	//cout << convert(1) << endl;
	//cout << convert(123) << endl;
	//cout << Z0(6) << endl;
	//cout << Z0t(7) << endl;
	//cout << Z1(8) << endl;
	//cout << Z2(255) << endl;
	return 0;
}