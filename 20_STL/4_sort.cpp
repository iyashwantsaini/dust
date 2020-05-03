#include<iostream>
#include<algorithm>
using namespace std;

class Interval{
    public:
        int starttime;
        int endtime;
};

bool compare(Interval i1, Interval i2){
    //inc order
    return i1.starttime<i2.starttime;
    //dec order
    // return i1.starttime>i2.starttime;
}

int main(){
    // int arr[]={1,3,2,5,4,7};
    //sort in inc order
    // sort(arr,arr+6);
    // for(int i=0;i<6;i++){
    //     cout<<arr[i]<<" ";
    // }
    //sort in dec order
    // sort(arr,arr+6,greater<int>());
    // for(int i=0;i<6;i++){
    //     cout<<arr[i]<<" ";
    // }

    
    //sort interval based on starting index
    // Interval arr[]={{6,4},{3,4},{4,6},{8,13}};
    // sort(arr,arr+4,compare);
    // for(int i=0;i<4;i++){
    //     cout<<arr[i].starttime<<" , "<<arr[i].endtime<<endl;
    // }

}