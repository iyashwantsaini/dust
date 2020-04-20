#include<bits/stdc++.h>
using namespace std;

// In this program we will create binary tree using queue using arrays
#include "queueCpp.h"

// For iterative traversals we need to provide our own stack -- to backtrack
#include "stackCpp.h"

//postorder-iterative ==BUG

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

        //getroot
        Node* GetRoot(){
            return root;
        }
        
        //recursive-pre
        void PreOrderRec(Node *p){
            if(p){
                cout<<p->data<<" ";
                PreOrderRec(p->lchild);
                PreOrderRec(p->rchild);
            }
        }
        //iterative-pre
        void PreOrderIter(){
            Node *p=GetRoot();
            Stack st;
            while(p!=NULL||!st.isEmpty()){
                if(p!=NULL){
                    cout<<p->data<<" ";
                    st.push(p);
                    p=p->lchild;
                }else{
                    p=st.pop();
                    p=p->rchild;
                }
            }
        }
        
        //recursive-in
        void InOrderRec(Node *p){
            if(p){
                InOrderRec(p->lchild);
                cout<<p->data<<" ";
                InOrderRec(p->rchild);
            }
        }
        //iterative-in
        void InOrderIter(){
            Node *p=GetRoot();
            Stack st;
            while(p!=NULL||!st.isEmpty()){
                if(p!=NULL){
                    st.push(p);
                    p=p->lchild;
                }else{
                    p=st.pop();
                    cout<<p->data<<" ";
                    p=p->rchild;
                }
            }
        }

        //recursive-post
        void PostOrderRec(Node *p){
            if(p){
                PostOrderRec(p->lchild);
                PostOrderRec(p->rchild);
                cout<<p->data<<" ";
            }
        }
        //iterative-post    === BUG!    
        void PostOrderIter(){
            Node *p=GetRoot();
            Stack st;

            intptr_t temp; //for storing address of NODE // intptr_t can store pointer values w/o losing precision
            while(p!=NULL||!st.isEmpty()){
                if(p!=NULL){
                    st.push(p);
                    p=p->lchild;
                }else{
                    temp=intptr_t(st.pop());
                    if(temp>0){
                        st.push((Node*)(-temp));
                        p=((Node*)temp)->rchild; //typecasting this +ve adress to a node address
                    }else{
                        cout<<((Node*)temp)->data<<" ";
                        p=NULL;
                    }
                }
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

};

int main(){

    Tree t;
    t.CreateTree();
    cout<<endl;

    cout<<"Preorder Recursive!"<<endl;
    t.PreOrderRec(t.GetRoot());
    cout<<endl;

    cout<<"Preorder Iterative!"<<endl;
    t.PreOrderIter();
    cout<<endl;

    cout<<"Inorder Recursive!"<<endl;
    t.InOrderRec(t.GetRoot());
    cout<<endl;

    cout<<"Inorder Iterative!"<<endl;
    t.InOrderIter();
    cout<<endl;
    
    cout<<"Postorder Recursive!"<<endl;
    t.PostOrderRec(t.GetRoot());
    cout<<endl;
    
    // cout<<"Postorder Iterative!"<<endl;
    // t.PostOrderIter();
    // cout<<endl;

    cout<<"Levelorder Traversal!"<<endl;
    t.LevelOrder(t.GetRoot());
    cout<<endl;

    return 0;
}