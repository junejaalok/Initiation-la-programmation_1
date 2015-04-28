#include <iostream>
#include <cmath>
using namespace std;

int power2 (int i) {
	if (i == 1) return 2;
	if (i==0) return 0;
	else {
		return (power2(i-1))+(power2(i-1));
	}

}

int main() {

cout << power2(4) << endl;

//i=pow(2,10)*pow(2,10)*pow(2,10);
int i=power2(100);
int summe=0;
/*  while (i >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
*/

	while (i>0) {
		summe+=i%10;
		i/=10;
	}
	cout << summe << endl;

}