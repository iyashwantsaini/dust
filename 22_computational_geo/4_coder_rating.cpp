#include<bits/stdc++.h>
using namespace std;
// each index of BIT will shows that patrical index coder is good than how many coders

// sample input
// 8
// 1798 1832
// 862 700
// 1075 1089
// 1568 1557
// 2575 1984
// 1033 950
// 1656 1649
// 1014 1473


class coder{
    public:
        int x,y,index;
};

int BIT[100001]; //each index contains no of coders smaller int level than that coder

void update(int y){
    for(;y<=10000;y+=y&(-y)){
        BIT[y]++;
    }
}

int query(int y){
    int val=0;
    for(;y>0;y-=y&(-y)){
        val+=BIT[y];
    }
    return val;
}

bool operator <(coder A,coder B){
    if(A.x==B.x){
        return A.y<B.y;
    }
    return A.x<B.x;
}

int main(){
    int n;
    cin>>n;
    coder arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
        arr[i].index=i;
    }
    sort(arr,arr+n); // this fn will use the overloaded operator automatically

    int ans[n];
    for(int i=0;i<n;){ 

        int endindex=i; //this is for case if two or more coders have same x and y
        // so we need to update this for every same level code simultainously
        
        while(endindex<n&&arr[endindex].x==arr[i].x&&arr[endindex].y==arr[i].y){
            endindex++;
        }
        for(int j=i;j<endindex;j++){
            // query
            ans[arr[j].index]=query(arr[j].y);
        }
        for(int j=i;j<endindex;j++){
            // update
            update(arr[j].y);
        }
        i=endindex;
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }


}