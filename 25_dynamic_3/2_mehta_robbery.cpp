#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// sample input
// 3 4
// 1 1
// 2 1
// 3 1
// output
// 152

int main(){
    int n,w;
    cin>>n;
    cin>>w;
    pair<ll,ll> *arr=new pair<ll,ll>[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+n);
    // 3d dp
    // i=prime using
    // j=no of items
    // k=weight
    ll ***dp=new ll**[2];
    for(int i=0;i<2;i++){
        dp[i]=new ll*[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=new ll[w+1];
            for(int k=0;k<=w;k++){
                dp[i][j][k]=0;
            }
        }
    }
    // top 10 primes
    int primes[11]={1,2,3,5,7,11,13,17,19,23,29};
    // base case
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            // current not included
            dp[0][i][j]=dp[0][i-1][j];
            // current include
            // only include if current weight is smaller than given max
            if(j>=arr[i-1].second){
                dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-arr[i-1].second]+arr[i-1].first);
            }
        }
    }

    // include primes and solve ans
    for(int prime=1;prime<=10;prime++){
        int p=prime%2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                dp[p][i][j]=dp[p][i-1][j];
                if(j>=arr[i-1].second){
                    dp[p][i][j]=
                    max(dp[p][i][j],
                        max(
                            dp[p][i-1][j-arr[i-1].second]+arr[i-1].first,
                            dp[p^1][i-1][j-arr[i-1].second]+arr[i-1].first*primes[prime]
                        )
                    );
                }
            }
        }
    }
    cout<<dp[0][n][w]<<endl;
    return 0;
}