#ifndef stackCpp_h
#define stackCpp_h

//JUST BASIC STACK

#include<bits/stdc++.h>
using namespace std;

class Node{  //node of a tree  
    public:
        Node *lchild=NULL;
        int data=0;
        Node *rchild=NULL;
};

class Stack{
    private:
        int size;
        int top;
        Node **s;
    public:
        Stack(){
            size=10;
            s=new Node*[size];
            top=-1;
        }
        Stack(int sizegiven){
            size=sizegiven;
            s=new Node*[size];
            top=-1;
        }
        ~Stack(){
            delete s;
        }
        void push(Node *x){
            if(top>=size-1){
                // cout<<"Stack Full!"<<endl;
                return;
            }
            top=top+1;
            s[top]=x;
            // cout<<"Pushed : "<<x<<" at index : "<<top<<endl;
        }
        Node* pop(){
            Node *bakup=NULL;
            if(top<0){
                // cout<<"Stack Empty!"<<endl;
                return bakup;
            }
            bakup=s[top];
            top=top-1;
            // cout<<"Popped : "<<bakup<<" from index : "<<top+1<<endl;
            return bakup;
        }
        int isEmpty(){
            if(top==-1){
                // cout<<"Empty!"<<endl;
                return 1;
            }else{
                // cout<<"Not Empty!"<<endl;
                return 0;
            }
        }
        Node* getTopElement(){
            if(top==-1){
                return NULL;
            }
           return s[top]; 
        }
};

#endif