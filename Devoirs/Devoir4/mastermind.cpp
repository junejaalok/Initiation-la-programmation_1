#include <iostream>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::random_device rd;
std::default_random_engine generateur(rd());

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const size_t nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
  bool ans=false;
  static const char* colors = ".RGBCYM";
  for (int i=0;i<7;i++) {
    if (colors[i]==c) ans=true;
  }
  return ans;
}

// ======================================================================
bool verifier(char c1, char& r1, int& score)
{
  if (c1==r1) {
    r1='x';
    score++;
    return true;
  }
  else {
    return false;
  }
}

// ======================================================================
void apparier(char c1, char& r1, char& r2, char& r3, int& score)
{
  if (r1 != 'x' && verifier(c1, r1, score)) c1='x';
  if (r2 != 'x' && verifier(c1, r2, score)) c1='x';
  if (r3 != 'x' && verifier(c1, r3, score)) c1='x';
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
  bool debug=false;
  char gus[4]={c1,c2,c3,c4};
  char ref[4]={r1,r2,r3,r4};
  int chk[4];
  int rcrp=0; //right color right placed
  int rcwp=0; //right color wrong placed
  int wcwp=0; //wrong color wrong placed
  for (int i=0;i<4;i++) {
    chk[i]=verifier(ref[i],gus[i],rcrp);
    if (chk[i]) ref[i]='x';
  }

  if (debug) {
    cout << "chk: " << chk[0] << chk[1] << chk[2] << chk[3] << endl;
    cout << "gus: " << gus[0] << gus[1] << gus[2] << gus[3] << endl;
    cout << "ref: " << ref[0] << ref[1] << ref[2] << ref[3] << endl;
  }

    if (gus[0]!='x') apparier(gus[0], ref[1], ref[2], ref[3], rcwp);
//    cout << "ref0: " << ref[0] << ref[1] << ref[2] << ref[3] << endl;
    if (gus[1]!='x') apparier(gus[1], ref[0], ref[2], ref[3], rcwp);
//    cout << "ref1: " << ref[0] << ref[1] << ref[2] << ref[3] << endl;
    if (gus[2]!='x') apparier(gus[2], ref[0], ref[1], ref[3], rcwp);
//    cout << "ref2: " << ref[0] << ref[1] << ref[2] << ref[3] << endl;
    if (gus[3]!='x') apparier(gus[3], ref[0], ref[1], ref[2], rcwp);
//    cout << "ref3: " << ref[0] << ref[1] << ref[2] << ref[3] << endl;
//    cout << "---------" << endl;

  wcwp=(4-(rcrp+rcwp));
  if (debug) {
    cout << "rcrp: " << rcrp << endl;
    cout << "rcwp: " << rcwp << endl;
    cout << "wcwp: " << wcwp << endl;
  }
  afficher(rcrp, '#');
  afficher(rcwp, '+');
  afficher(wcwp, '-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
  bool ans=false;
  if (c1==r1 && c2==r2 && c3==r3 && c4==r4) 
    ans=true;
  return ans;
}

// ======================================================================
void jouer(int games=8)
{
  //char ref[4]={'M','.','.','R'};
  char ref[4];
  for (int j=0;j<4;j++) {
    ref[j]=tirer_couleur();
  }
//  cout << ref << endl;
  int curr=1;
  while (curr<=games) {
    int num=0;
    char gus[4];
    while (num<4) {
      gus[num]=lire_couleur();
      num++;
    }

    if (num==4) {
      afficher_coup(gus[0],gus[1],gus[2],gus[3],ref[0],ref[1],ref[2],ref[3]);
    }

    bool correct=gagne(ref[0],ref[1],ref[2],ref[3],gus[0],gus[1],gus[2],gus[3]);
    if (curr<=games && correct) {
      message_gagne(curr);
      break;
    }
    else if (curr==games && !correct)
      message_perdu(ref[0],ref[1],ref[2],ref[3]);

    curr++;
  }
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
