#include<iostream>
using namespace std;

int c(int n,int r){
	if(r==0||r==n){
		return 1;
	}else{
		return c(n-1,r-1)+c(n-1,r);
	}
}

int main(){
	int n{},r{};
	cout<<"enter n: ";
	cin>>n;
	cout<<"enter r: ";
	cin>>r;
	cout<<"nCr = "<<c(n,r);
}
