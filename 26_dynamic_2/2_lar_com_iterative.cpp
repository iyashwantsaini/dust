// largest commmon subsequence
#include<bits/stdc++.h>
using namespace std;
// sample
// abcd50efgmh
// a1b2c3defgn79h
// out
// 8

int lcs(char *s1,char *s2){
    int m=strlen(s1);
    int n=strlen(s2);
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1]; 
    }
    // base cases
    // 0th rows and cols = 0 
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    // fill other all
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            // if first char is same of left string
            // remember i and j are last char of arrays
            if(s1[m-i]==s2[n-j]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans=dp[m][n];
    for(int i=0;i<=m;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){
    char a[100];
    char b[100];
    cin>>a;
    cin>>b;
    cout<<lcs(a,b)<<endl; 

}