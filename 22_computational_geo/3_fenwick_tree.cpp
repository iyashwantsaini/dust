#include<bits/stdc++.h>
using namespace std;

// 8
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8

void update(int index,int val, int *BST,int n){
    for(;index<=n;index+=index&(-index)){
        BST[index]+=val;
    }
}

int query(int index,int *BIT){
    int sum=0;
    for(;index>0;index-=index&(-index)){
        sum+=BIT[index];
    }   
    return sum;
}

int main(){
    int n;
    cin>>n;

    int *arr=new int[n+1]();
    int *BIT=new int[n+1]();

    for(int i=1;i<n+1;i++){
        cin>>arr[i];
        update(i,arr[i],BIT,n);
    }

    cout<<"sum of 0 to 5 elements : "<<query(5,BIT)<<endl;
    cout<<"sum of 2 to 6 elements : "<<query(6,BIT)-query(1,BIT)<<endl;

    return 0;
}