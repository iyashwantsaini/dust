#include<bits/stdc++.h>
using namespace std;

void merge_two(int *d,int low,int mid,int high){
    int merged[high-low+1];
    int i=low,j=mid+1,k=0;
    while(i<=mid&&j<=high){
        if(d[i]<d[j]){ merged[k++]=d[i++];}
        else{merged[k++]=d[j++];}
    }
    while(i<=mid){merged[k++]=d[i++];}
    while(j<=high){merged[k++]=d[j++];}
    for(int x=low;x<=high;x++){
        d[x]=merged[x-low];
    }
}

void merge_sort(int *d,int low,int high){
    int mid;
    if(low<high){
        mid=(high+low)/2;
        merge_sort(d,low,mid);
        merge_sort(d,mid+1,high);
        merge_two(d,low,mid,high);
    }
}

int main(){
    // int n;
    // cout<<"Enter no of elements - ";
    // cin>>n;
    int n=6;
    int data[n]={2,1,9,5,10,4};
    // for(int i=0;i<n;i++){
    //     cout<<"Enter element ("<<i<<") - ";
    //     cin>>data[i];
    // }
    merge_sort(data,0,n-1);
    cout<<"Sorted array - "<<endl;
    for(int i=0;i<n;i++){
        cout<<data[i]<<" ";
    }cout<<"\n";
}