#include<iostream>
using namespace std;

int sumfn(int n){
	static int sum{};
	if(n>0){
		sum+=n;
		sumfn(n-1);
	}
	return sum;
}

int main(){
	int n{};
	cout<<"enter n : ";
	cin>>n;
	cout<<"sum = "<<sumfn(n);
	
}
