// largest commmon subsequence
#include<bits/stdc++.h>
using namespace std;
// sample
// abcdefg
// 1234567
// out
// 0
// sample
// abcd50efgmh
// a1b2c3defgn79h
// out
// 8

// slow solution 
// int lcs(char *s1,char *s2){
//     // base cases
//     if(s1[0]=='\0'||s2[0]=='\0'){
//         return 0;
//     }
//     // othercases
//     // first char of both is same
//     if(s1[0]==s2[0]){
//         return 1+lcs(s1+1,s2+1);
//     }
//     // first char is not same
//     // reduce each one by one & get max
//     else{
//         int option1=lcs(s1,s2+1);
//         int option2=lcs(s1+1,s2);
//         return max(option1,option2);
//     }
// }

int helper(char *s1,char *s2,int m,int n,int **dp){
    if(m==0||n==0){
        return 0;
    }
    // get from storage
    if(dp[m][n]>-1){
        return dp[m][n];
    }
    // othercases
    int ans;
    // first char of both is same
    if(s1[0]==s2[0]){
        ans=1+helper(s1+1,s2+1,m-1,n-1,dp);
    }
    // first char is not same
    // reduce each one by one & get max
    else{
        int option1=helper(s1,s2+1,m,n-1,dp);
        int option2=helper(s1+1,s2,m-1,n,dp);
        ans=max(option1,option2);
    }
    dp[m][n]=ans;
    return ans;
}

int lcs(char *s1,char *s2){
    int m=strlen(s1);
    int n=strlen(s2);
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    int ans=helper(s1,s2,m,n,dp);
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
