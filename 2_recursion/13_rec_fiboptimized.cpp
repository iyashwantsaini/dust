#include<iostream>
#include<vector>
using namespace std;

int fib(int n){
	static vector<int> fibarr(n);
	for(int i=0;i<=n;i++){
		fibarr[i]=-1;
	}
	
	if(n<=1){
		fibarr[n]=n;
		return n;
	}else{
		if(fibarr[n-1]==-1){
			fibarr[n-1]=fib(n-1);
		}
		if(fibarr[n-2]==-1){
			fibarr[n-2]=fib(n-2);
		}
		return fibarr[n-1]+fibarr[n-2];
	}
}

int main(){
	int n;
	cout<<"enter n: ";
	cin>>n;
	cout<<"fib(n) = "<<fib(n);
	return 0;
}
