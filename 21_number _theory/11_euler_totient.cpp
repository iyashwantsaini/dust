#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// we'll use the same concept as we used in sieve 

int main(){

    int n;
    cout<<"Enter n : "<<endl;
    cin>>n;

    int phi[n+1];
    for(int i=0;i<=n;i++){
        phi[i]=i;
    }
    
    for(int i=2;i<=n;i++){
        if(phi[i]==i){ //if its same than it means its prime
            phi[i]=i-1; //every prime p has p-1 coprimes
            for(int j=2*i;j<=n;j+=i){
                phi[j]=(phi[j]*(i-1))/i; //*(1-(1/i)
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"Euler totient phi("<<i<<")="<<phi[i]<<endl;
    }
    
}