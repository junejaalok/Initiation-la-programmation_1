#include <iostream>
using namespace std;

int main(){


int a(8);
int b(5);
int c(3);

while(b < 7){
	if (a < c){
		++a;
	}
	else{
		--c;
	}
	++b;
}

if ((a < b) && (a + c > b)){
	cout<<"1"<<" ";
}
else{
	cout<<"2"<<" ";
}
if (a < c){
	cout<<"3"<<" ";
}
else{
	cout<<"4"<<" ";
	if (2*a > b){
		cout<<"5"<<" ";
	}
}
    return 0;
}