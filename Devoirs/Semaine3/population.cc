#include <iostream>
#include <iomanip> // pour setprecision()
#include <cmath>   // pour exp()
using namespace std;

int main()
{
  // réduire le format d'affichage
  cout << setprecision(4);

  constexpr double population_initiale(7.0); // population initiale, en milliard d'humains
  constexpr int    annee_depart(2011);       // année initiale
  double taux(1.2);                          // taux de croissance, en %

  int annee(annee_depart);                // année de calcul
  double population(population_initiale); // population mondiale pour l'année 'annee'

  cout << "====---- PARTIE 1 ----====" << endl;
  cout << "Population en " << annee << " : " << population
       << endl;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 ===== 
  while (annee<=annee_depart) {
    cout << "Quelle année (> " << annee_depart << ") ? ";
    cin >> annee;
  }

  cout << "Population en " << annee << " : " << population_initiale*exp((annee-annee_depart)*(taux/100)) << endl;

  // ===== PARTIE 2 =====
  cout << endl << "====---- PARTIE 2 ----====" << endl;
  while (population<=population_initiale) {
    cout << "Combien de milliards (> " << population_initiale << ") ? ";
    cin >> population; 
  }

  int i=annee_depart+1;
  double j=population_initiale;
  while (j<=population) {
    j= population_initiale*exp((i-annee_depart)*(taux/100));
    cout << "Population en " << i << " : " << j << endl;
    i++;
  }

  // ===== PARTIE 3 =====
  cout << endl << "====---- PARTIE 3 ----====" << endl;
  int k=annee_depart;
  i=k+1;
  j=population_initiale;
  double z=population_initiale;
  while (j<=population) {
    j= z*exp((i-k)*(taux/100));
    if (j>=z*2) {
      z=j;
      k=i;
      taux /=2.0;
    }
    cout << "Population en " << i << " : " << j << " ; taux de croissance : " << taux << " %" << endl;
    i++;
  }

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
