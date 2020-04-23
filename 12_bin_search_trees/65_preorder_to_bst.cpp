#include<bits/stdc++.h>
using namespace std;

#include "stackCpp.h"

//commenting ndoe becoz its already included in stack

// class Node{ 
//     public:
//         Node *lchild=NULL;
//         int data=0;
//         Node *rchild=NULL;
// };

class BST{
    private:
        Node *root;
    public:
        BST(){
            root=NULL;
        }
        BST(int *a){
            int size=sizeof(a)/sizeof(a[0]);
            Stack st;
            Node *t;
            Node *p;
            int i=0;

            //root making
            root=new Node();
            root->data=a[i++];
            p=root;

            //making other nodes
            while(i<size){
                if(a[i]<p->data){
                    t=new Node();
                    t->data=a[i++];
                    p->lchild=t;
                    st.push(p);
                    p=t;
                }else{
                    if(a[i]>p->data&&a[i]>st.getTopElement()->data){
                        t=new Node();
                        t->data=a[i++];
                        p->rchild=t;
                        p=t;
                    }else{
                        p=st.pop();
                    }
                }
            }
        }
        ~BST(){
            //delete_tree_nodes_from_heap
        }
        void PreOrder(Node *p){
            if(p){
                cout<<p->data<<" ";
                PreOrder(p->lchild);
                PreOrder(p->rchild);
            }
        }
        Node* GetRoot(){
            return root;
        }
};

int main(){
    int arr[]={10,20,8,17,3,25,9,30,16};
                        //         10
                        //     8   ||    20
                        //   3   9 ||  17  25
                        //         ||16      30
    BST bst(arr);
    bst.PreOrder(bst.GetRoot());    
}