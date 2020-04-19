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
        void PreOrder(Node *p){
            if(p){
                cout<<p->data<<" ";
                PreOrder(p->lchild);
                PreOrder(p->rchild);
            }
        }
        void PostOrder(Node *p){
            if(p){
                PostOrder(p->lchild);
                PostOrder(p->rchild);
                cout<<p->data<<" ";
            }
        }
        void InOrder(Node *p){
            if(p){
                InOrder(p->lchild);
                cout<<p->data<<" ";
                InOrder(p->rchild);
            }
        }
        void LevelOrder(Node *root){
            Queue q(100);
            cout<<root->data<<" ";
            q.Enqueue(root);

            while(!q.isEmpty()){
                root=q.Dequeue();
                if(root->lchild){
                    cout<<root->lchild->data<<" ";
                    q.Enqueue(root->lchild);
                }
                if(root->rchild){
                    cout<<root->rchild->data<<" ";
                    q.Enqueue(root->rchild);
                }
            }
        }
        int count(Node *root){
            static int nodecount=0;
            if(root){
                nodecount+=1;
                return count(root->lchild)+count(root->rchild)+1;
            }
            return 0;
        }
        int Height(Node *root){
            int x=0,y=0;
            if(root==NULL){
                return 0;
            }
            x=Height(root->lchild);
            y=Height(root->rchild);
            if(x>y){
                return x+1;
            }else{
                return y+1;
            }
        }
        Node* GetRoot(){
            return root;
        }
};

int main(){

    Tree t;
    t.CreateTree();
    cout<<endl;

    cout<<"Preorder Traversal!"<<endl;
    t.PreOrder(t.GetRoot());
    cout<<endl;
    
    cout<<"Postorder Traversal!"<<endl;
    t.PostOrder(t.GetRoot());
    cout<<endl;
    
    cout<<"Inorder Traversal!"<<endl;
    t.InOrder(t.GetRoot());
    cout<<endl;
    
    cout<<"Levelorder Traversal!"<<endl;
    t.LevelOrder(t.GetRoot());
    cout<<endl;

    cout<<"Height of tree : "<<t.Height(t.GetRoot());

    return 0;
}