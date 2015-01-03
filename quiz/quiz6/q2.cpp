

#include <iostream>
#include <string>
using namespace std;

void go(string s1, string s2);
int conv(string s);

int main() {
  /* appel function go */ 	go("560", "56");
  return 0;
}

int conv(string s) {
  int i(0);
  for(size_t j(0); j < s.size(); ++j) {
    i = i*10 +  (s[j] - '0');
    // (s[j] - '0') convertit le caractere '0' en l'entier 0, '1' -> 1, '2 '-> 2, etc.
  }
  return i;
}

void go(string s1, string s2) {
  string sub1;
  string sub2;
  int v(conv(s2));
  size_t size(s1.size());
  for (size_t i(0); i < size; ++i) {
    sub1 = s1.substr(0,i+1);
    sub2 = s1.substr(i+1, size - i);
    if (i+1 == size) sub2 = "0";
    if ((conv(sub1) + conv(sub2)) == v) {
       cout << sub1 <<  " + " << sub2;
       cout << " = " << v << endl;
    }
  }
}

