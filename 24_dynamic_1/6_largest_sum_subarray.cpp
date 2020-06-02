#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// this is kadane's algo

// sample 
// 8
// -5 6 7 -20 3 5 8 -9
// output
// 16
int kadane(int *a,int n){
    int current_sum=0;
    int best_sum=0;
    for(int i=0;i<n;i++){
        current_sum+=a[i];
        if(best_sum<current_sum){
            best_sum=current_sum;
        }
        if(current_sum<0){
            current_sum=0;
        }
    }
    return best_sum;
}

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<kadane(a,n)<<endl;
}