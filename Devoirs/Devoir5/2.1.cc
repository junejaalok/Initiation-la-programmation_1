#include <iostream>
#include <vector>

using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/



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
