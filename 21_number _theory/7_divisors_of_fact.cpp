// number of divisors of a factorial (n!)

#include<bits/stdc++.h>
using namespace std;
#define MAX 500001
#define mod 1000000007 //mod=10^9 +7
#define pb push_back
typedef long long ll;

vector<int> sieve(){
    bool isPrime[MAX];
    vector<int> primes;
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=MAX;i++){
        isPrime[i]=true;
    }
    for(int i=2;i*i<=MAX;i++){
        for(int j=i*i;j<=MAX;j+=i){
            isPrime[j]=false;
        }
    }
    primes.pb(2);
    for(int i=3;i<=MAX;i+=2){
        if(isPrime[i]){
            primes.pb(i);
        }
    }
    return primes;
};

ll divisors(int n,vector<int> &primes){
    ll result=1;
    for(int i=0;primes.at(i)<=n;i++){
        int k=primes.at(i);
        ll count =0;
        while((n/k)!=0){
            count=(count+(n/k))%mod;
            k=k*primes[i];
        }
        result=(result*(count+1)%mod)%mod;
    }
    return result;
}

int main(){
    vector<int> primes=sieve();
    cout<<divisors(2,primes);cout<<"\n";
    cout<<divisors(3,primes);cout<<"\n";
    cout<<divisors(4,primes);cout<<"\n";
}