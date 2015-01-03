#include <iostream>
#include <vector>
using namespace std;


int main()
{
vector<int> v;  
vector<int> u(3,1);
for(size_t i(1); i < u.size(); ++i) {
	u[i] = u[i] + 2 + i;
}
v = u;
u.clear();
v.push_back(7);
v.push_back(8);
v[0] = 0;
cout << v[0] << v[1] << v[2] << v[3] << v[4] << endl;
		
    return 0;
}