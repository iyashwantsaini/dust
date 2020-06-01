// aggressive cows
// sample input
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9
// output --largest min distance possible
// 3
// remember 
// 1st stall must have a cow

// o(nlog(d))

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int cows,ll positions[],int n,ll distance){
    // insert at 1st posn
    int count=1;
    ll last_posn=positions[0];

    // insert at others considering distance
    for(int i=0;i<n;i++){
        if(positions[i]-last_posn>=distance){
            last_posn=positions[i];
            count++;
        }
        if(count==cows){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;

        ll positions[n];
        for(int i=0;i<n;i++){
            cin>>positions[i];
        }
        sort(positions,positions+n);

        ll start=0;
        ll end=positions[n-1]-positions[0];
        ll ans=-1;    

        while(start<=end){
            ll mid =start+(end-start)/2;
            if(check(c,positions,n,mid)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

