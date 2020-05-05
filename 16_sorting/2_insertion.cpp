#include<bits/stdc++.h>
using namespace std;

//bug

//insertion in a sorted array in a sorted position
// in 1 pass we dont get anything useful
//array ---O(1)-O(n)
//link list ---O(1)-O(n)
// passes--n-1
// comparisions--n(n-1)/2
// swaps--n(n-1)/2

class Node{
    public:
        int data=0;
        Node *next=NULL;
};
int main(){
    // using array/vector
    // vector<int> v={1,3,5,7,15,30};
    // int el=12;
    // v.push_back(el);
    // int i=0;
    // for(i=v.size()-1;v[i-1]>el&&i>0;i--){
    //         v[i]=v[i-1];
    // }
    // v[i]=el;

    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }cout<<"\n";

    // using ll --more useful
    vector<int> v={1,3,5,7,15,30};
    int el=12;
    Node *first;
    Node *p=NULL;
    for(int i=0;i<v.size();i++){
        if(i==0){
            p=new Node();
            first=p;
            p->data=v[i];
        }
        p->next=new Node();
        p->next->data=v[i];
        p=p->next;
    }
    p=first;
    for(int i=0;i<v.size()+1;i++){
        cout<<p->data<<" ";
        p=p->next;
    }
}