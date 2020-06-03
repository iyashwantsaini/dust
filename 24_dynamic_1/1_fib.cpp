#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// very very slow soln 
// int fib(int n){
//     if(n==0||n==1){
//         return 1;
//     }
//     return fib(n-1)+fib(n-2);
// }

// improved recursively o(2n)
ll fib2(ll n,ll *a){
    if(n==0|n==1){
        return 1; 
    }
    if(a[n]>0){
        return a[n];
    }
    ll output =fib2(n-1,a)+fib2(n-2,a);
    a[n]=output;
    return output;
}

// improved iteratively o(n) --best
ll fib3(ll n){
    ll *arr=new ll[n+1]();
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    ll output=arr[n];
    delete [] arr;
    return output;
}

int main(){
    ll n;
    cin>>n;
    // cout<<fib(n)<<endl;

    // ll *a=new ll[n]();
    // cout<<fib2(n,a)<<endl;

    cout<<fib3(n)<<endl;
}