#include <iostream>
#include <vector>

using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
bool chk (vector <int> vec, int val) {
	bool ans=false;
	for (int i=0;i<vec.size();i++) {
		if (val==vec[i]) return true;
	}
	return ans;
}

int plus_frequent(vector<int>tableau,int& freq) {
	vector<int> freq_val;
	int temp;
	vector <int> chkd(1,0);
	for (int i=0;i<tableau.size();i++) 
	{
		temp=tableau[i];
		int temp_freq=1;
		if (!chk(chkd,temp)) {
			for (int j=i+1;j<tableau.size();j++) {
				if (temp==tableau[j]) {
					temp_freq++;
				}
			}
			chkd.push_back(temp);
		}

		if (temp_freq>freq) {
			freq=temp_freq;
			freq_val.push_back(temp);
		}
	}
//	for (int i=0;i<freq_val.size();i++) {
//		cout << freq_val.at(i) << endl;
//	}

	return freq_val.back();
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  vector<int> tableau = { 2, 7, 5, 6, 7, 1, 6, 2, 1, 7 };
  int freq(0);
  int best(plus_frequent(tableau, freq));
  cout << "Le nombre le plus fréquent dans le tableau est le "
       << best << " (" << freq << " x)." << endl;
  return 0;
}
