#include <iostream>
#include <string>
using namespace std;

void affichage(int n, bool b);

int main ()
{
  int const CINQ(5);
  bool const VRAI(true);

  affichage(CINQ, VRAI);
  affichage (2*CINQ, !VRAI);
  return 0; 
}

void affichage(int n, bool b)
{ 
  bool bb(b);
  for (int i(0); i < (n-2); ++i){
    int j(0);
    if (!bb){
      do {
    if (i > j){
      cout<< j <<endl;
      ++j;
    }
    else {
      bb = !bb;
      ++j;}
      }
      while(j < n);}
    else {
      if (i > 0) {
    cout << i << endl;}
      else {
    cout << b << endl;}
    }
  }
}