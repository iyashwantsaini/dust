#include<bits/stdc++.h>
using namespace std;

long long int fib(long long int n,long long int fibarr[]){
    if(n==0||n==1){
        return 1;
    }
    if(fibarr[n]!=-1){
        return fibarr[n];
    }
    long long int res=fib(n-1,fibarr)+fib(n-2,fibarr);
    fibarr[n]=res;
    return res;
}

int main(){
    long long int n=50;
    long long int fibarr[n+1];
    for(long long int i=0;i<n+1;i++){
        fibarr[i]=-1;
    }
    cout<<fib(n,fibarr);
}