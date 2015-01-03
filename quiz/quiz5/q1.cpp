#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> v{1,2,3,4};
    cout << v[1] << endl;
    vector<vector<int>> tab(5 , vector<int>(10));
    cout << tab[0][1] << endl;
    return 0;
}