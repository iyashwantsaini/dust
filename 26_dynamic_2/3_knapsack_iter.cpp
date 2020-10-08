#include<bits/stdc++.h>
using namespace std;\

int knapsack(int *val,int *wt,int W,int n){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[W+1];
    }
    // basecases
    // fill 0th row and 0th col
    for(int i=0;i<=W;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    // fill other
    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            dp[i][w]=dp[i-1][w];
            if(wt[i-1]<=W){
                dp[i][w]=max(dp[i][w],val[i-1]+dp[i-1][w-wt[i-1]]);
            }
        }
    }
    int ans=dp[n][W];
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
    cout<<knapsack(val,wt,W,n)<<endl;
    // ans=13
}