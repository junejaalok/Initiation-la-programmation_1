#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  while (renards_i<2.0) {
    cout << "Combien de renards au départ (>= 2) ? ";
    cin >> renards_i;
  }
  while (lapins_i<5.0) {
    cout << "Combien de lapins au départ  (>= 5) ? ";
    cin >> lapins_i;
  }

  // ===== PARTIE 2 =====
  // Première simulation
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  double renards_f;
  double lapins_f;
  double nb_renards=renards_i;
  double nb_lapins=lapins_i;
  for (int i=1;i<=duree;i++) {
    lapins_f = nb_lapins*(1.0 + taux_croissance_lapins - taux_attaque * nb_renards);
    renards_f = nb_renards*(1.0 + taux_attaque * nb_lapins * taux_croissance_renards - taux_mortalite);
    nb_lapins=lapins_f;
    nb_renards=renards_f;
    if (nb_lapins<0.0) nb_lapins=0.0;
    if (nb_renards<0.0) nb_renards=0.0;
    cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
  }

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  cout << endl;
  taux_attaque=0.0;
  while (taux_attaque < 0.5 or taux_attaque > 6.0) {
    cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
    cin >> taux_attaque;
  }

  double taux_final;
  do {
    cout << "taux d'attaque à la fin  en % (entre ";
    cout << taux_attaque;
    cout << " et 6) ? ";
    cin >> taux_final;
  } while (taux_final < taux_attaque or taux_final > 6);

  while (taux_attaque < taux_final) {
    cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque << "%" <<  endl;
    nb_renards=renards_i;
    nb_lapins=lapins_i;
    bool happened=false;
    bool renards_ex=false;
    bool lapins_ex=false;
    bool renards_rec=false;
    bool lapins_rec=false;
    bool renards_dis=false;
    bool lapins_dis=false;
    bool break_early=false;
    int i;
    for (i=1;i<=duree;i++) {
      lapins_f = nb_lapins*(1.0 + taux_croissance_lapins - (taux_attaque/100) * nb_renards);
      renards_f = nb_renards*(1.0 + (taux_attaque/100) * nb_lapins * taux_croissance_renards - taux_mortalite);

      nb_lapins=lapins_f;
      nb_renards=renards_f;

      if (nb_renards<5.0) {
        renards_ex=true;
      }
      if (nb_renards>=5.0 and renards_ex) {
        renards_rec=true;
        renards_ex=false;
      }
      if (nb_renards<2.0) {
        nb_renards=0.0;
        renards_dis=true;
      }
 
      if (nb_lapins<5.0) {
        lapins_ex=true;
      }
      if (nb_lapins>=5.0 and lapins_ex) {
        lapins_rec=true;
        lapins_ex=false;
      }
      if (nb_lapins<2.0) {
        nb_lapins=0.0;
        lapins_dis=true;
      }

      if (nb_renards<0.0) nb_renards=0.0;
      if (nb_lapins<0.0) nb_lapins=0.0;

      if (!nb_lapins and !nb_renards) {
        break_early=true;
        break;
      }
    }
  
    if (break_early)
      cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
    else
      cout << "Après " << duree << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;

    if (renards_ex) {
      cout << "Les renards ont été en voie d'extinction" << endl;
      happened=true;
    }
    if (renards_rec) {
      cout << "Les renards ont été en voie d'extinction" << endl;
      cout << "mais la population est remontée ! Ouf !" << endl;
      happened=true;
    }
    if (renards_dis) {
      cout << "et les renards ont disparus :-(" << endl;
      happened=true;
    }
    if (lapins_ex) {
      cout << "Les lapins ont été en voie d'extinction" << endl; 
      happened=true;
    }
    if (lapins_rec) {
      cout << "Les lapins ont été en voie d'extinction" << endl; 
      cout << "mais la population est remontée ! Ouf !" << endl;
      happened=true;
    }
    if (lapins_dis) {
      cout << "et les lapins ont disparus :-(" << endl;
      happened=true;
    }
    if (!happened) cout << "Les lapins et les renards ont des populations stables." << endl;
    taux_attaque++;
  }


  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
