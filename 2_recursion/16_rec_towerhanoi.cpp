#include<iostream>
#include<string>
using namespace std;

void toh(int n,string a,string b,string c){
	if(n>0){
		toh(n-1,a,c,b);
		cout<<a<<" to "<<c<<endl;
		toh(n-1,b,a,c);
	}
}

int main(){
	int n;
	string a,b,c;
	cout<<"enter no. of disks : ";
	cin>>n;
	cout<<"enter name of 3 pillars : ";
	cin>>a>>b>>c;
	cout<<"steps for moving disks from "<<a<<" to "<<c<<" : "<<endl;
	toh(n,a,b,c);
}
