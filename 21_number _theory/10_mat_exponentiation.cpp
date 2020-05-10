// program to find nth fibonacci nnumber using matrix exponentiation

#include<bits/stdc++.h>
using namespace std;

void multiply(int A[2][2],int m[2][2]){
    // using 3 nested loops complexity
    int c[2][2]={0};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c[i][k]+=A[i][j]*m[j][k];
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            A[i][j]=c[i][j];
        }
    }
}

void power(int A[2][2],int n){
    if(n==0||n==1){
        return;
    }
    
    power(A,n/2);
    // multi a^(n/2) * a^(n/2)
    multiply(A,A);

    // for odd
    if(n%2!=0){
        int M[2][2]={
            {1,1},
            {1,0}
        };
        multiply(A,M);
    }
}

int fibonacci(int n){
    int A[2][2]={
        {1,1},
        {1,0}
    };
    if(n==0){
        return 0; //0th fibonacci number is 0 itself
    }
    power(A,n-1); //using matrix exponentiation

    return A[0][0];
}

int main(){
    cout<<fibonacci(8); //we need to find 6th number of fiboacci series
}