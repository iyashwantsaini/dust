#include<iostream>
using namespace std;

int main(){
	
	int *p;
	p=new int[5];
	cout<<"p's data : ";
	for(int i=0;i<5;i++){
		p[i]=i*i;
		cout<<p[i];
	}
	
	int *q;
	q=new int[10];
	for(int i=0;i<10;i++){
		q[i]=p[i];
	}
	
	delete []p;
	p=q;
	q=NULL;
	
	cout<<"\nnew p's data : ";
	for(int i=0;i<5;i++){
		p[i]=i*i;
		cout<<p[i];
	}
	
	
}
