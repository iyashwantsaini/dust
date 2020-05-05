#include<bits/stdc++.h>
using namespace std;

//effect similar to when we throw a heavy stone in water
// in 1 pass we get highest element
// n elements -- n-1 passes
//comparisions -- n(n-1)/2  // O(n^2)
// max swaps -- n(n-1)/2  // O(n^2)

//adaptive -- add flag to keep track of when no swap occurs then we stop

int main(){
    int arr[]={1,5,9,2,0,3,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    // ans=0,1,2,3,5,8,9
    int flag=0; 
    for(int i=0;i<size;i++){ //for passes
        flag=0;
        for(int j=i+1;j<size;j++){ //for comparision
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
                flag=1;
            }
        }
        if(flag==0){ //means list already sorted
            break;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";
}