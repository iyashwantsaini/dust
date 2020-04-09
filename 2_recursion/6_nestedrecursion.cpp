#include<iostream>
using namespace std;

int fun(int n){
	if(n>100){
		return n-10;
	}else{
		return fun(fun(n+11));
	}
}

int main(){
	int n=0;
	cout<<"enter n : ";
	cin>>n;
	cout<<fun(n);
}
