#include<iostream>
using namespace std;

//slower version
//int power(int m,int n){
//	if(n==0){
//		return 1;
//	}else{
//		return power(m,n-1)*m;
//	}
//}

//faster version
int power(int m, int n){
	if(n==0){
		return 1;
	}else if(n%2==0){
		return power(m*m,n/2);
	}else{
		return m*power(m*m,(n-1)/2);
	}
}
int main(){
	int num{},expo{};
	cout<<"enter num: ";
	cin>>num;
	cout<<"enter power: ";
	cin>>expo;
	cout<<"result : "<<power(num,expo);
}
