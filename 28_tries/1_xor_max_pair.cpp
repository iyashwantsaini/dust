#include<bits/stdc++.h>
using namespace std;

// insert query -- nlog(max element)

class trieNode{
    public:
        trieNode *left=NULL; //left is 0
        trieNode *right=NULL; //right is 1
};

void insert(int n,trieNode *head){
    trieNode *current=head;
    for(int i=31;i>=0;i--){
        // finding leftmost bit of num
        int b=(n>>i)&1;
        // left
        if(b==0){
            // left is not present
            if(!current->left){
                current->left=new trieNode();
            }
            current=current->left;
        // right
        }else{
            // right is not present
            if(!current->right){
                current->right=new trieNode();
            }
            current=current->right;
        }
    }
}

int maxXorPair(trieNode *head,int *arr,int n){
    int max_xor=INT_MIN;
    for(int i=0;i<n;i++){
        int currentval=arr[i];
        trieNode *current=head;
        int current_xor=0;
        for(int j=31;j>=0;j--){
            int b=(currentval>>j)&1;
            // right
            if(b==0){
                if(current->right){
                    current=current->right;
                    current_xor+=pow(2,j);
                }else{
                    current=current->left;
                }
            // left
            }else{
                if(current->left){
                    current=current->left;
                    current_xor+=pow(2,j);
                }else{
                    current=current->right;
                }
            }
        }
        if(current_xor>max_xor){
            max_xor=current_xor;
        }
    }
    return max_xor;
}

int main(){
    int arr[6]={8,1,2,15,10,5};
    // insert in trie
    trieNode *head=new trieNode();
    for(int i=0;i<6;i++){
        insert(arr[i],head);
    }
    // get max XOR pair
    cout<<maxXorPair(head,arr,6)<<endl;
    return 0;
}