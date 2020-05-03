#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    
    //binary search --array must be sorted
    // only tells true or force
    // int arr[]={1,3,5,7,9,11};
    // cout<<binary_search(arr,arr+6,5)<<endl;
    // cout<<binary_search(arr,arr+6,4)<<endl;

    //lower bound -- returns pointer to that position
    //lower bound first sorts array then searches
    // int arr[]={1,5,3,2,7};
    // cout<<lower_bound(arr,arr+5,2)<<endl; //gives pointer
    // cout<<lower_bound(arr,arr+5,2)-arr<<endl;
    //if not found it uses next highest 
    // cout<<lower_bound(arr,arr+5,4)-arr<<endl; 

    //upper bound --always gives result for 1 higher
    // int arr[]={1,5,3,2,7};
    // cout<<upper_bound(arr,arr+5,3)-arr;

}