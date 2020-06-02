#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// sample
// 5
// 2 5 1 3 4
// output
// 4

ll merge(int *a,int left,int rstart,int right){
    int i=left;
    int j=rstart;
    int k=0; 
    int *temp=new int[right-left+1];

    ll counts=0;
    while(i<rstart&&j<=right){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
            counts+=rstart-i;
        }
    }
    while(i<rstart){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++){
        a[i]=temp[k];
    }
    return counts;
}

ll merge_sort(int *a,int left,int right){
    ll count=0;
    if(right>left){
        int mid=(left+right)/2;
        ll leftcount= merge_sort(a,left,mid);
        ll rightcount=merge_sort(a,mid+1,right);
        ll finalcount=merge(a,left,mid+1,right);
        return leftcount+rightcount+finalcount;
    }
    return count;
}

ll solve(int *a,int n){
    ll ans=merge_sort(a,0,n-1);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a,n);
}