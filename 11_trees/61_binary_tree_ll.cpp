#include<bits/stdc++.h>
using namespace std;

// In this program we will create binary tree using queue using arrays
#include "queueCpp.h"

class Tree{
    private:
        Node *root; //This node is a node of tree
    public:
        Tree(){
            root=NULL;
        }
        ~Tree(){

        }
        void CreateTree(){
            Node *p,*t;
            int x;
            //creating queue array of size 100
            Queue q(100);

            //creating root node
            cout<<"Enter root value: ";
            cin>>x;
            root=new Node();
            root->data=x;

            //add node address to queue
            q.Enqueue(root);
            
            //make other nodes
            while(!q.isEmpty()){

                //p will be used to find is l or r child exists or not
                p=q.Dequeue();

                //lchild of p
                cout<<"Enter LEFT child of "<<p->data<<" : ";
                cin>>x;
                if(x!=-1){ //ie lchild exists
                    t=new Node(); //so creating new node for left child
                    t->data=x;
                    p->lchild=t; //linking 't' to its parent
                    q.Enqueue(t);
                }
                //rchild of p
                cout<<"Enter RIGHT child of "<<p->data<<" : ";
                cin>>x;
                if(x!=-1){ //ie lchild exists
                    t=new Node(); //so creating new node for left child
                    t->data=x;
                    p->rchild=t; //linking 't' to its parent
                    q.Enqueue(t);
                }

            }

        }
        //recursive
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

    Tree t;
    cout<<"**Enter -1 for NULL**"<<endl;
    t.CreateTree();
    cout<<endl;

    cout<<"Preorder Traversal!"<<endl;
    t.PreOrder(t.GetRoot());
    cout<<endl;

    return 0;
}