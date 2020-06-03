#include<bits/stdc++.h>
using namespace std;

int helper(int *val,int *wt,int W,int n,int **dp){
    // base case
    if(W==0||n==0){
        return 0;
    }
    // other cases
    // get from storage
    if(dp[n][W]>0){
        return dp[n][W];
    }
    // if not in storage  
    if(wt[n-1]<=W){
        int ans=max(val[n-1]+helper(val,wt,W-wt[n-1],n-1,dp),helper(val,wt,W,n-1,dp));
        dp[n][W]=ans;
        return ans;
    }else{
        int ans=helper(val,wt,W,n-1,dp);
        dp[n][W]=ans;
        return ans;
    }
}

int knapsnack(int *val,int *wt,int W,int n){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[W+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=0;
        }
    }
    int ans= helper(val,wt,W,n,dp);
    for(int i=0;i<=n;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){
    int val[]={5,4,8,6};
    int wt[]={1,2,3,5};
    int W=5;
    int n=4;
    cout<<knapsnack(val,wt,W,n)<<endl;
}