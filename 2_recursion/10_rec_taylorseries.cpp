#include<iostream>
using namespace std;

//recursive method
float e(float x, float n){
	static float p{1};
	static float f{1};
	float r;
	
	if(n==0){
		return 1;
	}else{
		r=e(x,n-1);
		p=p*x;
		f=f*n;
		return r+p/f;
	}
}

int main(){
	
	cout<<e(1,10);
	
}










