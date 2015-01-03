#include <iostream>
#include <sstream>
#include <string>
using namespace std;


int demander_annee(void) {
	int annee;
	string mystr;
	do {
		cout << "Entrez une annee (1583-4000) : ";
		getline (cin,mystr);
		stringstream(mystr) >> annee;
	} while (annee < 1583 || annee > 4000);
	return annee;
}


void affiche_date (int annee, int num) {
	string month;
	if (num<=31) month=" mars";
	else {
		num-=31;
		month=" avril";
	}
	cout << "Date de Paques en " << annee << " : " << num << month << endl;

}

int date_Paques (int annee) {
	int days,a,p,q,M,N,d,e;
	int century;
	century=annee/100;
	a=annee % 19;
	p=(13+(8*century))/25;
	q=century/4;
	M=(15 - p + century - q)%30;
	N=(4 + century - q)%7;
	d=(19*a + M)%30;
	e=(2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7;
	days=d + e + 22;
	if (e == 6) {
		if (d == 29 and days == 57) {
			days = 50; 
		}
		else if (d == 28 and (((11*M + 11) % 30) < 19) and days == 56) {
			days = 49;
		}
	}
	return days;
}


int main()
{
	int annee=demander_annee();
	int num=date_Paques (annee);
	affiche_date (annee, num);
  return 0;
}
