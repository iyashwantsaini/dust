#include<bits/stdc++.h>
using namespace std;
// sample
// 3 1
// abc 10
// ball 15
// bag 5
// ba
// output
// 15
class trienode{
    public:
        trienode** children;
        int weight;
        // constructor
        trienode(){
            children=new trienode*[26];
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            weight=0;
        }
};

void insert(string s,int weight,trienode *root){
    // base case
    if(s.empty()){
        return;
    }
    trienode *child;
    int index=s[0]-'a';

    if(root->children[index]){
        child=root->children[index];
    }else{
        child=new trienode();
        root->children[index]=child;
    }

    if(root->weight<weight){
        root->weight=weight;
    }
    insert(s.substr(1),weight,child);
}

int searchbest(string s,trienode *root){
    int bestweight=-1;
    trienode *current=root;
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        trienode *child=current->children[index];
        if(child){
            current=child;
            bestweight=child->weight;
        }else{
            return -1;
        }
    }
    return bestweight;
}

int main(){
    int n,q;
    cin>>n>>q;
    trienode *root=new trienode();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int weight;
        cin>>weight;
        insert(s,weight,root);    
    }
    for(int i=0;i<q;i++){
        string pre;
        cin>>pre;
        cout<<searchbest(pre,root)<<endl;
    }
}