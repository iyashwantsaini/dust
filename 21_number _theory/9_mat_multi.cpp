// simple program for matrix multiplication

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3][3]={ //3x3 i,j
        {1,0,1},
        {1,1,1},
        {0,1,0}
    };
    int b[3][2]={ //3x2 j,k
        {1,2},
        {3,1},
        {1,1}
    };

    // so multi c ==> i*j x j*k = i*k

    int c[3][2]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                c[i][k]+=a[i][j]*b[j][k];
            }
        }
    }

    // print c
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
}
