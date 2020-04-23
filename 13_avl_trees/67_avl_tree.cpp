#include<bits/stdc++.h>
using namespace std;

//here we are starting height from 1

class Node{
    public:
        Node* lchild=NULL;
        Node* rchild=NULL;
        int height=0;   // to find balance factor of each node
        int data=0;
};

class AVL{
    private:
        Node *root;
    public:
        AVL(){
            root=NULL;
        }
        ~AVL(){
            // delete all nodes from heap
        }
        Node* GetRoot(){
            return root;
        }
        int NodeHeight(Node *p){  //can calculate height of each node
            int hl=0,hr=0;

            hl=p && p->lchild?p->lchild->height:0;
            hr=p && p->rchild?p->rchild->height:0;

            return hl>hr?hl+1:hr+1;
        }
        int BalanceFactorNode(Node *p){ //calc bf of each node
            int hl=0,hr=0;

            hl=p && p->lchild?p->lchild->height:0;
            hr=p && p->rchild?p->rchild->height:0;

            return hl-hr;
        }

        //recursive-pre
        void PreOrderRec(Node *p){
            if(p){
                cout<<p->data<<" ";
                PreOrderRec(p->lchild);
                PreOrderRec(p->rchild);
            }
        }

        Node* LLRotation(Node *p){
            Node *pl=p->lchild;
            Node *plr=pl->rchild;

            pl->rchild=p;
            p->lchild=plr;

            p->height=NodeHeight(p);
            pl->height=NodeHeight(pl);
            
            if(p==root){
                root=pl;
            }
            return pl;
        }
        Node* LRRotation(Node *p){
            Node *pl=p->lchild;
            Node *plr=pl->rchild;

            pl->rchild=plr->lchild;
            p->lchild=plr->rchild;
            plr->lchild=pl;
            plr->rchild=p;

            p->height=NodeHeight(p);
            pl->height=NodeHeight(pl);
            plr->height=NodeHeight(plr);

            if(p==root){
                root=plr;
            }
            return plr;
        }
        Node* RRRotation(Node *p){
            Node *pr=p->rchild;
            Node *prl=pr->lchild;

            pr->lchild=p;
            p->rchild=prl;

            p->height=NodeHeight(p);
            pr->height=NodeHeight(pr);
            
            if(p==root){
                root=pr;
            }
            return pr;
        }
        Node* RLRotation(Node *p){
            Node *pr=p->rchild;
            Node *prl=pr->lchild;

            pr->lchild=prl->rchild;
            p->rchild=prl->lchild;
            prl->lchild=p;
            prl->rchild=pr;

            p->height=NodeHeight(p);
            pr->height=NodeHeight(pr);
            prl->height=NodeHeight(prl);

            if(p==root){
                root=prl;
            }
            return prl;
        }

        Node* InsertNode(Node *p,int key){
            Node *t=NULL;
            if(root==NULL){
                t=new Node();
                t->data=key;
                t->height=1;
                root=t;
                return root;
            }
            if(p==NULL){  //ie we have to create a new leaf node
                t=new Node();
                t->data=key;
                t->height=1;
                return t;
            }
            if(key<p->data){  //add key to lchild
                p->lchild=InsertNode(p->lchild,key);
            }else if(key>p->data){  //add key to rchild
                p->rchild=InsertNode(p->rchild,key);
            }

            p->height=NodeHeight(p);

            if(BalanceFactorNode(p)==2 && BalanceFactorNode(p->lchild)==1){ //left heavy
                cout<<"Performing LL rotation"<<endl;
                return LLRotation(p);
            }else if(BalanceFactorNode(p)==2 && BalanceFactorNode(p->lchild)==-1){  //left-then-right heavy
                cout<<"Performing LR rotation"<<endl;
                return LRRotation(p);
            }else if(BalanceFactorNode(p)==-2 && BalanceFactorNode(p->rchild)==-1){ //right heavy
                cout<<"Performing RR rotation"<<endl;
                return RRRotation(p);
            }else if(BalanceFactorNode(p)==-2 && BalanceFactorNode(p->rchild)==1){ //right-then-left heavy
                cout<<"Performing RL rotation"<<endl;
                return RLRotation(p);
            }

            return p;
        }
};

int main(){

    AVL avl;

    // // ll rotation
    // avl.InsertNode(avl.GetRoot(),10);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;
    // avl.InsertNode(avl.GetRoot(),5);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;
    // avl.InsertNode(avl.GetRoot(),2);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;

    // // lr rotation
    // avl.InsertNode(avl.GetRoot(),10);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;
    // avl.InsertNode(avl.GetRoot(),5);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;
    // avl.InsertNode(avl.GetRoot(),7);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;

    // // rr rotation
    // avl.InsertNode(avl.GetRoot(),10);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;
    // avl.InsertNode(avl.GetRoot(),20);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;
    // avl.InsertNode(avl.GetRoot(),30);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;

    // // rl rotation
    // avl.InsertNode(avl.GetRoot(),10);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;
    // avl.InsertNode(avl.GetRoot(),30);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;
    // avl.InsertNode(avl.GetRoot(),20);
    // avl.PreOrderRec(avl.GetRoot());cout<<endl;

}


