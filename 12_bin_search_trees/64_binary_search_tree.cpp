#include<bits/stdc++.h>
using namespace std;

class Node{  //node of a tree
    public:
        Node *lchild=NULL;
        int data=0;
        Node *rchild=NULL;
};

class BSTree{
    private:
        Node *root;
    public:
        BSTree(){
            root=NULL;
        }
        ~BSTree(){
            //delete_from_heap
        }
        Node* GetRoot(){
            return root;
        }
        int Height(Node *p){
            if(p==NULL){
                return 0;
            }else{
                return LevelCount(p)-1;
            }
        }
        int LevelCount(Node *p){
            int x,y;
            if(p==NULL){
                return 0;
            }else{
                x=LevelCount(p->lchild);
                y=LevelCount(p->rchild);
                if(x>y){
                    return x+1;   
                }else{
                    return y+1;
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
        void InsertIter(int key){
            Node *t=NULL,*p=GetRoot(),*r=GetRoot();
            if(GetRoot()==NULL){
                t=new Node();
                t->data=key;
                root=t;
                cout<<"Inserted "<<key<<" at root"<<endl;
                return;
            }
            while(p!=NULL){ //this will not run if root is null i.e element is first element of tree
                r=p;
                if(p->data==key){
                    cout<<"Key already present in BST"<<endl;
                    return;
                }else if(p->data<key){
                    p=p->rchild;
                }else{
                    p=p->lchild;
                }
            }
            t=new Node();
            t->data=key;
            if(r->data>key){
                r->lchild=t;
            }else{
                r->rchild=t;
            }
            cout<<"Inserted "<<key<<" in tree"<<endl;
        }
        Node* InsertRec(Node *p,int key){
            Node *t=NULL;
            if(root==NULL){
                t=new Node();
                t->data=key;
                root=t;
                return t;
            }
            if(p==NULL){
                t=new Node();
                t->data=key;
                return t;
            }
            if(key==p->data){
                cout<<"Key already present in BST"<<endl;
                return NULL;
            }
            if(key>p->data){
                p->rchild=InsertRec(p->rchild,key);
            }else{
                p->lchild=InsertRec(p->lchild,key);
            }
            return p;
        }
        void SearchIter(int key){
            Node *p=GetRoot();
            while(p!=NULL){
                if(key==p->data){
                    cout<<"Key Found!"<<endl;
                    return;
                }else if(key>p->data){
                    p=p->rchild;
                }else{
                    p=p->lchild;
                }
            }
            cout<<"Key not found!"<<endl;
        }
        Node* SearchRec(Node *p,int key){
            if(p==NULL){
                return NULL;
            }
            if(key==p->data){
                cout<<"Key Found!"<<endl;
                return NULL;
            }else if(key>p->data){
                p->rchild=SearchRec(p->rchild,key);
            }else{
                p->lchild=SearchRec(p->lchild,key);
            }
            // cout<<"Key not found!"<<endl;
            return p;
        }

        //functions for delete!    
        Node* inorder_predecessor(Node *p){ //right most element of left subtree
            while(p&&p->rchild){
                p=p->rchild;
            }
            return p;
        }
        Node* inorder_successor(Node *p){ //left most element of right subtree 
            while(p&&p->lchild){
                p=p->lchild;
            }
            return p;
        }
        Node* DeleteRec(Node *p,int key){
            Node *q;
            if(p==NULL){ // leaf->next
                return NULL;
            }
            if(p->lchild==NULL&&p->rchild==NULL){ //leaf node
                if(p==root){
                    root=NULL;
                }
                delete p;
                return NULL;
            }
            if(key<p->data){
                p->lchild=DeleteRec(p->lchild,key);
            }else if(key>p->data){
                p->rchild=DeleteRec(p->rchild,key);
            }else{
                if(Height(p->lchild)>Height(p->rchild)){
                    q=inorder_predecessor(p->lchild);
                    p->data=q->data;
                    p->lchild=DeleteRec(p->lchild,q->data);
                }else{
                    q=inorder_successor(p->rchild);
                    p->data=q->data;
                    p->rchild=DeleteRec(p->rchild,q->data);
                }
            }
            return p;  
        }

};

int main(){

    BSTree bst;

    // bst.PreOrder(bst.GetRoot());
    // bst.InsertIter(10);
    // bst.InsertIter(20);
    // cout<<"Preorder : "<<endl;
    // bst.PreOrder(bst.GetRoot());cout<<"\n";
    // bst.InsertIter(3);
    // bst.InsertIter(7);
    // cout<<"Preorder : "<<endl;
    // bst.PreOrder(bst.GetRoot());cout<<"\n";
    // bst.InsertIter(2);
    // bst.InsertIter(17);
    // cout<<"Preorder : "<<endl;
    // bst.PreOrder(bst.GetRoot());cout<<"\n";

    // bst.SearchIter(10);
    // bst.SearchIter(17);
    // bst.SearchIter(3);
    // bst.SearchIter(15);

    // bst.SearchRec(bst.GetRoot(),10);
    // bst.SearchRec(bst.GetRoot(),17);
    // bst.SearchRec(bst.GetRoot(),3);
    // bst.SearchRec(bst.GetRoot(),15);

    bst.PreOrder(bst.GetRoot());
    bst.InsertRec(bst.GetRoot(),10);
    bst.InsertRec(bst.GetRoot(),20);
    bst.InsertRec(bst.GetRoot(),1);
    cout<<"Preorder : "<<endl;
    bst.PreOrder(bst.GetRoot());cout<<"\n";
    bst.InsertRec(bst.GetRoot(),3);
    bst.InsertRec(bst.GetRoot(),7);
    bst.InsertRec(bst.GetRoot(),15);
    cout<<"Preorder : "<<endl;
    bst.PreOrder(bst.GetRoot());cout<<"\n";
    bst.InsertRec(bst.GetRoot(),2);
    bst.InsertRec(bst.GetRoot(),17);
    bst.InsertRec(bst.GetRoot(),8);
    cout<<"Preorder : "<<endl;
    bst.PreOrder(bst.GetRoot());cout<<"\n";

    bst.DeleteRec(bst.GetRoot(),10);
    cout<<"Preorder : "<<endl;
    bst.PreOrder(bst.GetRoot());cout<<"\n";
    bst.DeleteRec(bst.GetRoot(),1);
    cout<<"Preorder : "<<endl;
    bst.PreOrder(bst.GetRoot());cout<<"\n";
    bst.DeleteRec(bst.GetRoot(),20);
    cout<<"Preorder : "<<endl;
    bst.PreOrder(bst.GetRoot());cout<<"\n";

    return 0;
}