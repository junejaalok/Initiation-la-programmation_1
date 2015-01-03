#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
  nombre*=10;
  nombre+=chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
    ajouter_chiffre_droit(nombre,repetitions_chiffre);
    ajouter_chiffre_droit(nombre,chiffre);
}

int lire_et_dire(int nombre)
{
  int result=0;
  int ldgt=separer_chiffre_gauche(nombre);   
  int rpt=1;

  while (nombre) {
    int temp=separer_chiffre_gauche(nombre);
//    cout << "ldgt: " << ldgt << " temp: " << temp << endl;
    if (ldgt==temp) {
//      cout << "C1" << endl;
      rpt+=1;
    }
    else {
//      cout << "C2" << endl;
//      cout << "rpt2: " << rpt << endl;
//      cout << "result2a: " << result << endl;
//      ajouter_chiffre_droit(result,rpt);
//      cout << "result2b: " << result << endl;
//      rpt=1;
      dire_chiffre(result,rpt,ldgt);
//      cout << "result2c: " << result << endl;
      ldgt=temp;
      rpt=1;
    }
  }
  //ajouter_chiffre_droit(result,rpt);
 // rpt=1;
  dire_chiffre(result,rpt,ldgt);
  return result;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre;
  int fois;
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
