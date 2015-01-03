#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> v(4,1);
	for(size_t i(0); i < v.size(); ++i) { 
		v[i] = i + 1;
	}	
	cout << v[0] << v[1] << v[2] << v[3] << endl;
		
    return 0;
}