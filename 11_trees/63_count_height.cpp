#include<bits/stdc++.h>
using namespace std;

// In this program we will create binary tree using queue using arrays
#include "queueCpp.h"

// BUG in deg 0,1,1or2 functions

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
        
        //count nodes - recursive
        int countNodes(Node *p){
            // int x=0,y=0;
            if(p!=NULL){
                
                // x=countNodes(p->lchild);
                // y=countNodes(p->rchild);
                // return x+y+1;

                // OR

                return countNodes(p->lchild)+countNodes(p->lchild)+1;
            }else{
                return 0;
            }
        }   

        //BUG
        int countNodesDeg0(Node *p){ // leafNodes / External Nodes
            int x=0,y=0;
            if(p->lchild!=NULL&&p->rchild!=NULL){
                x=countNodesDeg0(p->lchild);
                y=countNodesDeg0(p->rchild);
                return x+y+1;
            }
            else{
                return x+y;
            }
        }

        //BUG
        int countNodesDeg1(Node *p){
            int x=0,y=0;
            if(
                // (p->lchild==NULL&&p->rchild!=NULL)||(p->lchild!=NULL&&p->rchild==NULL) //XOR Operation
                // OR
                p->lchild!=NULL^p->rchild!=NULL
            ){
                x=countNodesDeg1(p->lchild);
                y=countNodesDeg1(p->rchild);
                return x+y+1;
            }
            else{
                return x+y;
            }
        }

        int countNodesDeg2(Node *p){
            int x=0,y=0;
            if(p->lchild!=NULL&&p->rchild!=NULL){
                x=countNodesDeg2(p->lchild);
                y=countNodesDeg2(p->rchild);
                return x+y+1;
            }
            else{
                return x+y;
            }
        }

        //BUG
        int countDeg1or2(Node *p){ // Internal Nodes
            int x=0,y=0;
            if(p->lchild==NULL||p->rchild==NULL){
                x=countDeg1or2(p->lchild);
                y=countDeg1or2(p->rchild);
                return x+y+1;
            }
            else{
                return x+y;
            }
        }

        int LevelsCount(Node *p){
            int x=0,y=0;
                if(p==NULL){
                    return 0;
                }
                x=LevelsCount(p->lchild);
                y=LevelsCount(p->rchild);
                if(x>y){
                    return x+1;
                }else{
                    return y+1;
                }
        }

        int Height(){
            return LevelsCount(GetRoot())-1;
        }

};

int main(){

    Tree t;
    t.CreateTree();
    cout<<endl;

    cout<<"Count All Nodes : "<<endl;
    cout<<t.countNodes(t.GetRoot());
    cout<<endl;
    
    cout<<"Count Nodes Deg = 0 : "<<endl;
    cout<<t.countNodesDeg0(t.GetRoot());
    cout<<endl;

    cout<<"Count Nodes Deg = 1 : "<<endl;
    cout<<t.countNodesDeg1(t.GetRoot());
    cout<<endl;

    cout<<"Count Nodes Deg = 2 : "<<endl;
    cout<<t.countNodesDeg2(t.GetRoot());
    cout<<endl;

    cout<<"Count Nodes Deg = 1 or 2 : "<<endl;
    cout<<t.countDeg1or2(t.GetRoot());
    cout<<endl;

    cout<<"Levels in Tree : "<<endl;
    cout<<t.LevelsCount(t.GetRoot());
    cout<<endl;

    cout<<"Height of Tree : "<<endl;
    cout<<t.Height();
    cout<<endl;

    // INPUTS:
    // 10
    // 20
    // 30
    // 40
    // 50
    // 60
    // -1
    // -1
    // -1
    // -1
    // -1
    // -1
    // -1

    return 0;
}