#include<iostream>
using namespace std;

//global
int x=0;
//result =25
int fun(int n){
	if(n>0){
		x++;
		return fun(n-1) +x;
	}
	return 0;
}

//static
//result =25
//int fun(int n){
//	static int x=0;
//	if(n>0){
//		x++;
//		return fun(n-1) +x;
//	}
//	return 0;
//}

//simple
//result =15
//int fun(int n){
//	if(n>0){
//		return fun(n-1) +n;
//	}
//	return 0;
//}

int main(){
	
	int n{};
	cout<<"enter n :";
	cin>>n;
	cout<<fun(n);
	
}
