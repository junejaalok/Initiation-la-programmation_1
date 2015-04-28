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
int annee_finale;
cout << "Quelle année (> "<<annee_depart<<") ? " ;
cin >> annee_finale;
while (annee_finale < annee_depart)
{
cout << "Quelle année (> "<<annee_depart<<") ?";
cin >> annee_finale;
}
int nb=annee_finale-annee_depart;
double population_finale= population_initiale * exp (nb * taux /100.0);
cout << "Population en "<<annee_finale <<" : " <<population_finale << endl;
  

  // ===== PARTIE 2 =====

  cout << endl << "====---- PARTIE 2 ----====" << endl;
double population_cible;
cout << "Combien de milliards (> "<<population_initiale<<") ? " ;
cin >> population_cible;
while (!(population_cible > population_initiale))
{
cout << "Combien de milliards(>" <<population_initiale << ") ? " ;
cin >> population_cible;
}
annee_finale=annee_depart +1;
nb=annee_finale-annee_depart;
double population_finale2=population_initiale * exp (nb * taux /100.0);
while (population_finale2 < population_cible){
nb=annee_finale-annee_depart;
population_finale2= population_initiale * exp (nb * taux /100.0);
cout << "Population en "<<annee_finale <<" : " <<population_finale2 << endl;
annee_finale ++;
} 

  // ===== PARTIE 3 =====
 cout << endl << "====---- PARTIE 3 ----====" << endl;
int annee_finale3;
annee_finale3=annee_depart +1;
int nb3;
nb3=annee_finale3-annee_depart;
double population_finale3=population_initiale * exp (nb3 * taux /100.0);
double rakam=population_initiale;
int annee_depart3=annee_depart;
double population_initiale3 = population_initiale;
while (population_finale3 < population_cible){
nb3=annee_finale3-annee_depart3;
population_finale3= population_initiale3 * exp (nb3 * taux /100.0);
cout << "Population en "<<annee_finale3 <<" : " <<population_finale3 << " ; ";
if (population_finale3 >= (rakam*2))
{
taux=taux/2.0;
rakam=population_finale3;
population_initiale3=population_finale3;
annee_depart3 = annee_finale3;
}
cout << "taux de croissance : " <<taux <<" %" <<endl;
annee_finale3 ++;
} 


  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
