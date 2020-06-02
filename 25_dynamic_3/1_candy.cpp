#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// sample
// 3
// 1 1 1
// 1 0 1
// 1 1 1
// output
// 
ll solvecandy(int **like,int n){
    ll dp[(1<<n)];
    for(int i=0;i<(1<<n)-1;i++){
        dp[i]=0;
    }
    // no candy is assigned to anyone --1 way for this
    dp[(1<<n)-1]=1;
    for(int mask=(1<<n)-2;mask>=0;mask--){
        // set candy for unassignmed person in each mask
        // count set bits --gives number of already assigned person
        int temp=mask;
        int k=0;
        while(temp>0){
            int lastbit=temp&1;
            k=k+lastbit;
            temp=temp/2;
        }
        // assign the remaining person
        for(int i=0;i<n;i++){
            if(like[k][i] && !(mask&(1<<i))){
                dp[mask]+=dp[mask | (1<<i)];
            }
        }
    }
    return dp[0];
}

int main(){
    int n;
    cin>>n;
    int **like=new int*[n];
    for(int i=0;i<n;i++){
        like[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>like[i][j];
        }
    }
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<n;j++){
    //         cout<<like[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<solvecandy(like,n)<<endl;
    return 0;
}