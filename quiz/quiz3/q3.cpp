#include <iostream>
using namespace std;

int main(){


int j(1);  
for (int i(0); i < 4 ; ++i) {
        j += i;
        cout << i << " " << j << " ";
}
    return 0;
}