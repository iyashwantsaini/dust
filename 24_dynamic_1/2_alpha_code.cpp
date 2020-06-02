// get no of codes of a particular number

#include<bits/stdc++.h>
using namespace std;

// slowest soln
// int num_codes(int *n,int size){
//     if(size==1){
//         return 1;
//     }
//     if(size==0){
//         return 1;
//     }
//     int output=num_codes(n,size-1);
//     if(n[size-2]*10+n[size-1]<=26){
//         output+=num_codes(n,size-2);
//     }
//     return output;
// }

// o(2n) --recursive
// int num_codes(int *n,int size,int *arr){
//     if(size==1){
//         return 1;
//     }
//     if(size==0){
//         return 1;
//     }
//     if(arr[size]>0){
//         return arr[size];
//     }
//     int output=num_codes(n,size-1,arr);
//     if(n[size-2]*10+n[size-1]<=26){
//         output+=num_codes(n,size-2,arr);
//     }
//     arr[size]=output;
//     return output;
// }

// o(n) --iterative
int num_codes(int *n,int size){
    int *output = new int[size+1];
    output[0]=1;
    output[1]=1;

    for(int i=2;i<=size;i++){
        output[i]=output[i-1];
        if(n[i-2]*10+n[i-2]<=26){
            output[i]+=output[i-2];
        }
    }
    int ans=output[size];
    delete output;
    return ans;
}

int main(){
    int n[4]={1,2,3,4};
    // cout<<num_codes(n,4)<<endl;

    // int *arr=new int[4]();
    // cout<<num_codes(n,4,arr)<<endl;

    cout<<num_codes(n,4)<<endl;
}