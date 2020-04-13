#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int arr[t];
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    int a,b;

    for(int i=0;i<t;i++){
        a=arr[i]-1;b=1;
        int cases=0;
        if(arr[i]==0||arr[i]==1||arr[i]==2){
            cout<<cases<<endl;
            continue;
        }
        while(a>b){
            a--;
            b++;
            cases++;
        }
        cout<<cases<<endl;
    }
}