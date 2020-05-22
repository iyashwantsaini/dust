#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// eg we need to find all primes between 47 and 700

int main(){
    // make sieve first
    int rootr=pow(2147483647,0.5);
    // int rootr=1000001;
    int sieve[rootr];
    for(int i=0;i<rootr;i++){
        sieve[i]=1;
    }
    sieve[0]=0;
    sieve[1]=0;
    int countprimes=0;
    for(int i=2;i*i<rootr;i++){
        if(sieve[i]==1){
            countprimes+=1;
            for(int j=i*i;j<rootr;j+=i){
                sieve[j]=0;
            }
        }
    }
    int primes[countprimes];
    int count=0;
    for(int i=0;i<rootr;i++){
        if(sieve[i]){
            primes[count++]=i;
        }
    }
    // for(int i=0;i<50;i++){
    //     cout<<primes[i]<<" ";
    // }

    ll l,r;
    cout<<"Enter L & R : ";
    cin>>l>>r;

    // mark multiples of primes from sieve 0 in L to R
    int ans[r-l+1];
    for(int i=0;i<=r-l;i++){
        ans[i]=1;
    }
    for(ll i=0;primes[i]*primes[i]<=r;i++){
        ll currentprime=primes[i];
        // find where to start from // just smaller or equal value
        ll base=(l/currentprime)*currentprime;
        // if base comes less than n add currentprime to reach next within range multiple
        if(base<l){
            base=base+currentprime;
        }
        for(ll j=base;j<=r;j+=currentprime){
            // j-l gives index of the multiple
            ans[j-l]=false;
        }
        // there maybe a case where base is itself a prime number
        if(base==currentprime){
            ans[base-l]=1;
        }
    }

    for(int i=0;i<=r-l;i++){
        if(ans[i]){
            cout<<i+l<<" ";
        }
    }

}