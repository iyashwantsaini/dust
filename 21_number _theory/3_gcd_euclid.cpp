#include<bits/stdc++.h>
using namespace std;

int GCDeuclid(int a, int b){
    // special case
    if(a<b){ //only runs 1 time
        return GCDeuclid(b,a);
    }

    //base case
    if(b==0){
        return a;

    // euclid step
    }else{
        return GCDeuclid(b,a%b);
    }
}

int main(){
    int a,b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    
    //method1
    // 
    // int gcd=0;
    // int minof2=min(a,b);
    // for(int i=1;i<minof2;i++){
    //     if(a%i==0&&b%i==0){
    //         gcd=i;
    //     }
    // }
    // cout<<"GCD : "<<gcd<<endl;

    //method2 --EUCLID
    // EUCLID works ony when a>b
    // cout<<"GCD : "<<GCDeuclid(max(a,b),min(a,b))<<endl;
    cout<<"GCD : "<<GCDeuclid(a,b)<<endl;

}