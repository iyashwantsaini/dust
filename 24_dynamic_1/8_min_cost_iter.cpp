#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// sample input
// 3
// 4 3 2
// 1 8 3
// 1 1 8

// iterative
int min_cost(int **a,int m,int n){
    int **dp=new int*[m];
    for(int i=0;i<m;i++){
        dp[i]=new int[n];
    }
    // fill base cases ie last whole row and col
    dp[m-1][n-1]=a[m-1][n-1];
    // fill last col complete
    for(int i=m-2;i>=0;i--){
        dp[i][n-1]=dp[i+1][n-1]+a[i][n-1];
    }
    // fill last row complete
    for(int i=n-2;i>=0;i--){
        dp[m-1][i]=dp[m-1][i+1]+a[m-1][i];
    }

    // fill all now rowise or colwise
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=a[i][j]+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
    }
    int ans=dp[0][0];
    // delete arrays
    for(int i=0;i<m;i++){
        delete [] dp[i];
    }
    delete dp;
    return ans;
}

int main(){
    // we are calculating from square
    // just take rows and cols if we need rectangle
    int dim;
    cin>>dim;
    int **a=new int*[dim];
    for(int i=0;i<dim;i++){
        a[i]=new int[dim];
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cin>>a[i][j];
        }
    }
    // we have to reach from (0,0) to (dim-1,dim-1)
    cout<<min_cost(a,dim,dim)<<endl; 

    // delete arrays
    for(int i=0;i<dim;i++){
        delete [] a[i];
    }
    delete a;
}