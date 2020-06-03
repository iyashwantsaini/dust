#include<bits/stdc++.h>
using namespace std;

// incomplete rec method
// bool helper(int *val,int n,int sum,bool **dp){
//     // base case
//     if(n==0){
//         return false;
//     }
//     // other cases
//     // check storage
//     if(dp[n][sum]>0){
//         return dp[n][sum];
//     }
//     // not in storage
//     // rec cases
//     if(val[n]>=0){
//         int ans=
//         dp[n][sum]=ans;
//         return ans;
//     }else{
//         int ans=
//         dp[n][sum]=ans;
//         return ans;
//     }
// }

bool subsetsum(int *val,int n,int sum){
    bool **dp=new bool*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new bool[sum+1];
    }
    // for rec case
    // int ans=helper(val,n,sum,dp);

    // base cases 
    // 1st row =0
    // 1st col =1 
    //  element at 0,0 =1
    for(int i=0;i<=sum;i++){
        dp[0][i]=false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    // find others
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];

            if(j>=val[i-1]){
                dp[i][j]=dp[i][j]||dp[i-1][j-val[i-1]];
            }
        }
    }
    int ans=dp[n][sum];
    for(int i=0;i<=n;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){
    int val[]={1,3,5,7,9};
    int sum=12;
    int n=5;
    cout<<subsetsum(val,n,sum)<<endl;
}