#include<bits/stdc++.h>
using namespace std;

// priority queue using 2 stacks

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack(){
            top=NULL;
        }
        ~Stack(){
            Node *p=top,*q;
            while(p){
                q=p;
                p=p->next;
                delete q;
            }
        }
        void push(int num){

            Node *t=top;
            Node *m=new Node();
            if(m==NULL){
                cout<<"Stack is full!"<<endl;
                return;
            }
            m->data=num;
            m->next=top;
            top=m;
            cout<<"Pushed : "<<num<<endl;
        }
        int pop(){
            if(top==NULL){
                cout<<"Stack is empty!"<<endl;
                return 0;
            }
            Node *t=top;
            int x=top->data;
            top=top->next;
            delete t;
            cout<<"Popped : "<<x<<endl;
            return x;
        }
        int isEmpty(){
            if(top==NULL){
                cout<<"Empty!"<<endl;
                return 1;
            }
            cout<<"Not Empty"<<endl;
            return 0;
        }
};

class Queue{
    private:
        Stack *s1; // to enq
        Stack *s2; // to deq
    public:
        Queue(){
            s1=new Stack();
            s2=new Stack();
        }
        ~Queue(){
            delete s1;
            delete s2;
        }
        void enq(int x){
            s1->push(x);
        }
        void deq(){
            if(s2->isEmpty()){
                while(!s1->isEmpty()){
                    s2->push(s1->pop());
                }
            }else{
                s2->pop();
            }
        }
};

int main(){

    Queue q;
    q.enq(10);
    q.enq(20);
    q.enq(30);
    q.enq(40);
    q.enq(50);
    q.enq(60);

    q.deq();
    q.deq();
    q.deq();
}