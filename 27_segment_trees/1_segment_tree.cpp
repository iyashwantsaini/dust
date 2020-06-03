#include<bits/stdc++.h>
using namespace std;
// remember -- always build a segemnt tree of 4n size
// update ans query in O(logn)

// buildtree
void buildtree(int *arr,int *tree,int start,int end,int treenode){
    // base case --when we reach leaf
    if(start==end){
        tree[treenode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}

void update(int *arr,int *tree,int start,int end,int treenode,int index,int value){
    // base case
    if(start==end){
        arr[index]=value;
        tree[treenode]=value;
        return;
    }
    // get mid
    int mid=(start+end)/2;
    if(index>mid){
    // goright 
        update(arr,tree,mid+1,end,2*treenode+1,index,value);
    }else{
    // go left
        update(arr,tree,start,mid,2*treenode,index,value);
    }
    // update in tree
    tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}

int query(int *tree,int start,int end,int treenode,int left,int right){
    // node completely outside given range
    if(start>right||end<left){
        return 0;
    }
    // node completely inside given range
    if(start>=left&&end<=right){
        return tree[treenode];
    }
    // node partially outside or inside given range
    int mid=(start+end)/2;
    int leftans=query(tree,start,mid,2*treenode,left,right);
    int rightans=query(tree,mid+1,end,2*treenode+1,left,right);
    return leftans+rightans;
}

int main(){
    int arr[]={1,2,3,4,5};

    // build tree of size 4n
    int *tree=new int[4*5];
    // 0-8 index of arrays 
    // 1 - from where tree should start -ie root 
    buildtree(arr,tree,0,4,1);
    cout<<"Tree build : "<<endl;
    for(int i=1;i<2*5;i++){
        cout<<tree[i]<<" ";
    }cout<<"\n";

    // update
    // put 10 at index 2 of array
    update(arr,tree,0,4,1,2,10);
    cout<<"Tree updated! : "<<endl;
    for(int i=1;i<2*5;i++){
        cout<<tree[i]<<" ";
    }cout<<"\n";

    // query
    // get sum between 2 and 4 index
    int ans =query(tree,0,4,1,2,4);
    cout<<"Sum between given interval : "<<ans<<endl;
    return 0;
}