#include <iostream>
using namespace std;

int main()
{
  cout << "Pensez a un personnage : Mlle Rose, le Professeur Violet, "
       << "le Colonel Moutarde," << endl
       << "le Reverend Olive ou Mme Leblanc." << endl << endl;

  cout << "Votre personnage a-t-il des homme ? ";
  bool homme;
  cin >> homme;
  if (!homme) {
    cout << "Votre personnage porte-t-il des lunettes ? ";
    bool lunettes;
    cin >> lunettes;
    if (!lunettes) {
      cout << "==> Le personnage auquel vous pensez est ";
      cout << "Mlle Rose";
    }
    else {        
      cout << "==> Le personnage auquel vous pensez est ";
      cout << "Mme Leblanc";
    }
  }
  else {
    cout << "Votre personnage a-t-il des moustaches ? ";
    bool moustaches;
    cin >> moustaches;
    if(moustaches) {
      cout << "==> Le personnage auquel vous pensez est ";
      cout << "le Colonel Moutarde";
    }
    else {
      cout << "Votre personnage porte-t-il un chapeau ? ";
      bool chapeau;
      cin >> chapeau;
      if (chapeau) {
        cout << "==> Le personnage auquel vous pensez est ";
        cout << "le Professeur Violet";
      }
      else {
        cout << "==> Le personnage auquel vous pensez est ";
        cout << "le Reverend Olive";
      }
    }
  }
  cout << endl;
  return 0;
}
