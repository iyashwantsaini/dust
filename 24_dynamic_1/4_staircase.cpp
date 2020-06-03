#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// slow
// ll no_of_ways(ll n){
//     if(n==0||n==1){
//         return 1;
//     }
//     if(n==2){
//         return 2;
//     }
//     ll result=no_of_ways(n-1)+no_of_ways(n-2)+no_of_ways(n-3);
//     return result;
// }

// dynamic iterative soln
ll no_of_ways(ll n){
    int *a=new int[n+1];
    a[0]=1;
    a[1]=1;
    a[2]=2; 
    for(int i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    int ans=a[n];
    delete [] a;
    return ans;
}

int main(){
    ll n;
    cin>>n;
    cout<<no_of_ways(n)<<endl;
}