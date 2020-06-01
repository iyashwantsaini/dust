#include<bits/stdc++.h>
using namespace std;

// nlogn

// sample input
// 5
// 1 1 2 1 3
// 3
// 1 5
// 2 4
// 3 5

int arr[30001]={0};
int bit[30001]={0};
int last[1000001];

class event{
    public:
        int first,second,index;
} query [2000001];

bool operator < (event a,event b){
    return a.second<b.second;
}

void update(int index,int value,int n){
    for(;index<=n;index+=index&(-index)){
        bit[index]+=value;
    }
}
int value(int index){
    int result=0;
    for(;index>0;index-=index&(-index)){
        result+=bit[index];
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>query[i].first>>query[i].second;
        query[i].index=i;
    }
    sort(query,query+q);

    // this sets every element of last as -1
    memset(last,-1,sizeof(last));
    int total=0;
    int k=0;
    int ans[q];
    for(int i=1;i<=n;i++){
         if(last[arr[i]]!=-1){
             update(last[arr[i]],-1,n);
         }else{
             total++;
         }
         update(i,1,n);
         last[arr[i]]=i;

         while(k<q&&query[k].second==i){
            ans[query[k].index]=total-value(query[k].first-1);
            k++;
         }
    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }

}