#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=50; //take input
    int count=0; //no of factors
    int noofprimes=0;

    // O(n^2)
    // for(int i=1;i<=n;i++){
    //     count=0;
    //     for(int j=1;j<=n;j++){
    //         if(i%j==0){
    //             count+=1;
    //         }
    //     }
    //     if(count==2){
    //         cout<<i<<" is prime!"<<endl;
    //         noofprimes+=1;
    //     }
    // }

    //O[n*{n^(1/2)}]
    // for(int i=1;i<=n;i++){
    //     count=0;
    //     for(int j=1;j*j<=i;j++){ //means j<root(n)
    //         if(i%j==0){
    //             if(j*j==i){
    //                 count+=1;
    //             }else{
    //                 count+=2;
    //             }
    //         }
    //     }
    //     if(count==2){
    //         cout<<i<<" is prime!"<<endl;
    //         noofprimes+=1;
    //     }
    // }

    // sieve of erathosthenes --storage is used to reduce time
    int arr[n]; //1=true,0==false //this array is called sieve
    for(int i=0;i<n;i++){
        arr[i]=1;
    }
    arr[0]=0;
    arr[1]=0;

    for(int i=2;i*i<=n;i++){ //we need to check only upto root(n)
        //making all multiples 0
        if(arr[i]==1){ //eg we dont need to run it for 4,6,8 etc.
            for(int j=i*i;j<=n;j=j+i){ //eg. 3 must start from 9, 5 must start from 25
                arr[j]=0;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(arr[i]==1){
            cout<<i<<endl;
        }
    }

}