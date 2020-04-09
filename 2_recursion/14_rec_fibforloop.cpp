#include<iostream>
using namespace std;

int fib(int n){
	int t0=0,t1=1,sum=1;
	if(n<=1){
		return n;
	}
	for(int i=2;i<=n;i++){
		sum=t0+t1;
		t0=t1;
		t1=sum;
	}
	return sum;
}

int main(){
	int n;
	cout<<"enter n: ";
	cin>>n;
	cout<<"fib("<<n<<")= "<<fib(n);
}
