#ifndef queueCpp_h
#define queueCpp_h

//JUST BASIC QUEUE

#include<bits/stdc++.h>
using namespace std;

class Node{  //node of a tree
    public:
        Node *lchild=NULL;
        int data;
        Node *rchild=NULL;
};

class Queue{
    private:
        int size;
        int front;
        int back;
        Node **storage;  // this queue now stores pointer to node
    public:
        Queue(){
            size=10;
            storage=new Node*[size];
            front=-1;
            back=-1;
        }
        Queue(int s){
            size=s;
            storage=new Node*[size];
            front=-1;
            back=-1;
        }
        ~Queue(){
            delete storage;
        }
        void Enqueue(Node *num){
            if(back==size-1){
                // cout<<"Queue Full!"<<endl;
                return;
            }
            back+=1;
            storage[back]=num;
            // cout<<"Added : "<<num<<" to index : "<<back<<endl;
        }
        Node* Dequeue(){
            Node *x=NULL;
            if(back==front){
                // cout<<"Queue Empty!"<<endl;
                // return;
            }
            x=storage[front+1];
            front+=1;
            return x;
        }
        int isEmpty(){
            if(back==front){
                // cout<<"Queue Empty!"<<endl;
                return 1;
            }else{
                return 0;
            }
        }
};

#endif