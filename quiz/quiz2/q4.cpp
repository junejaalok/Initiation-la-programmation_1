#include <iostream>
using namespace std;

int main(){


bool test1(not (true and (true or false)));
bool test2(false);

if (not test1){
    cout << "Ré" << " ";}
if (not (test1 or test2)){
    if (test1){
        cout << "Sol" << " ";}
    else{
        cout << "Fa" << " ";}
}
else{
    cout << "Mi" << " ";}
cout << "Fa" << " ";    return 0;
}