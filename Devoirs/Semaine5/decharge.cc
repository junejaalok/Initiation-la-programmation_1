#include <iostream>

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

#include <cmath>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  double x,y;
};

double distance(Point const& p1, Point const& p2){
  double val= sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
  return val;
}

typedef vector <Point> Commune;

Point plus_proche(Point const& depart, Commune const& village){
  Point pnt;
  double dist=999.0;
  for (int i=0;i<village.size();i++) {
    double temp=distance(depart,village.at(i));
    if (temp < dist) {
      dist=temp;
      pnt=village.at(i);
    }
  }
  return pnt;
}

typedef array <Point, 3> Triangle;

void delete_element(Point& trn, Commune& village) {
  for(vector<Point>::iterator it = village.begin(); it != village.end(); it=it+1) {
    if(it->x == trn.x && it->y==trn.y) {
      village.erase(it);
      return;
    }
  }
  return;
}

Triangle trois_plus_proches(Point const& depart, Commune const& village) {
  Triangle trn;
  Commune temp=village;
  for (int i=0;i<3;i++) {
    trn[i]=plus_proche(depart, temp);
    delete_element(trn[i],temp);
  } 
  return trn;
}

Point proposition(Point const& depart, Commune const& village){
  Triangle trn=trois_plus_proches(depart, village);
  Point pnt;
  pnt.x=0;
  pnt.y=0;
  for (int i=0;i<trn.size();i++) {
    pnt.x+=trn[i].x;
    pnt.y+=trn[i].y;
  }
  pnt.x/=3;
  pnt.y/=3;

  return pnt;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

// ----------------------------------------------------------------------
void affiche(Point const& maison)
{
  cout << "(" << maison.x << ", " << maison.y << ")";
}

// ----------------------------------------------------------------------
void affiche(Commune const& village)
{
  cout << "{" << endl;
  for(auto const& maison : village) {
    cout << "   ";
    affiche(maison);
    cout << endl;
  }
  cout << "}";
}

// ----------------------------------------------------------------------
void affiche(Triangle const& t)
{
  affiche(Commune({ t[0], t[1], t[2] }));
}

// ----------------------------------------------------------------------
void test(Point const& depart, Commune const& village)
{
  cout << "Pour le point ";
  affiche(depart);
  cout << " dans le village : ";
  affiche(village);
  cout << ", les distances à toutes les habitations sont :" << endl;
  for(auto const& maison : village) {
    cout << "   ";
    affiche(maison);
    cout << " --> " << distance(depart, maison) << endl;
  }
  cout << ", le point le plus proche est ";
  affiche(plus_proche(depart, village));
  cout << "," << endl << "les trois points les plus proches sont ";
  affiche(trois_plus_proches(depart, village));
  cout << ", et la nouvelle proposition de position est ";
  affiche(proposition(depart, village));
  cout << "." << endl;
}

// ----------------------------------------------------------------------
int main()
{
  const Commune commune = {
    {  1   ,  5    },
    {  1.25,  0.5  },
    {  3   ,  2    },
    {  5   ,  6.25 },
    {  5.5 ,  1.5  }
  };

  test( { 4, 3 }, commune);

  return 0;
}
