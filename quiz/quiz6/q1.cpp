#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	string s("rigolo"); 
	string s1("est");
	string s2;
	char c1('C');

	s.insert(6,"!");
	s2 = "'" + s1;
	s2 = c1 + s2;
	s = s2 + " " + s;
	cout << s << endl;
    return 0;
}