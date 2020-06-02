#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// d=array of denominations
// sample
// 4 2
// 1 2
// output 
// 3
int coin_change(int n, int *d,int num_den, int **storage){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(num_den==0){
        return 0;
    }
    if(storage[n][num_den]>-1){
        return storage[n][num_den];
    }
    int first = coin_change(n-d[0],d,num_den,storage);
    int second = coin_change(n,d+1,num_den-1,storage);
    storage[n][num_den]=first+second;
    return first+second;
}

int main(){
    int n; //rupees
    cin>>n;
    int num_den; //no of den of coins
    cin>>num_den;
    int *d=new int[num_den];
    for(int i=0;i<num_den;i++){
        cin>>d[i];
    }

    int **storage=new int*[n+1];
    for(int i=0;i<=n;i++){
        storage[i]=new int[num_den+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=num_den;j++){
            storage[i][j]=-1;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<num_den;j++){
    //         cout<<storage[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<coin_change(n,d,num_den,storage)<<endl;
}