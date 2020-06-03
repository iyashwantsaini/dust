#include<bits/stdc++.h>
using namespace std;

// here we'll only make 2 row array

bool subsetsum(int *val,int n,int sum){
    bool **dp=new bool*[2];
    for(int i=0;i<=1;i++){
        dp[i]=new bool[sum+1];
    }
    // base cases 
    // 1st row =0
    // 1st col =1 
    //  element at 0,0 =1
    for(int i=0;i<=sum;i++){
        dp[0][i]=false;
    }
    dp[0][0]=true;
    int flag=1;
    // find others
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[flag][j]=dp[flag^1][j];
            if(j>=val[i-1]){
                dp[flag][j]=dp[flag][j]||dp[flag^1][j-val[i-1]];
            }
        }
        flag=flag^1;
    }
    bool ans=dp[flag^1][sum];
    for(int i=0;i<=1;i++){
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