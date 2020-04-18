#include <bits/stdc++.h>
using namespace std;

// in this method elements themselves are priorities and must be handled accordingly
// we will make sure that elements are added in increasing order of their priorities : rule = lowest priority at end
// FIFO is not followed here

class Node{
    public:
        int data;
        Node *next=NULL;
};

class Queue{
    private:
        Node *front;
        Node *rear;
    public:
        Queue(){
            front=NULL;
            rear=NULL;
        }
        ~Queue(){
            Node *p=front;
            Node *q;
            while(p){
                q=p;
                p=p->next;
                delete q;
            }
        }
        void Enqueue(int x){
            Node *t=new Node();
            if(t==NULL){
                cout<<"Heap is FULL!"<<endl;
                return;
            }
            t->data=x;
            //if empty queue
            if(front==NULL){
                front=t;
                rear=t;
                cout<<"Enqueued "<<t->data<<" at front"<<endl;
            // if insert before head    
            }else if(front->data>x){
                t->next=front;
                front=t;
                cout<<"Enqueued before head"<<endl;
            // if rear is smaller than x
            }else if(rear->data<x){
                rear->next=t;
                rear=t;
                cout<<"Enqueued "<<t->data<<" at end"<<endl;
            // if front is smaller than x
            }else{
                Node *p=front;
                Node *q=front;
                while(p->data<x){
                    q=p;
                    p=p->next;
                }
                t->next=q->next;
                q->next=t;
                cout<<"Enqueued "<<t->data<<" at mid"<<endl;
            }
        }
        void Dequeue(){
            //just delete from end : as lowest priority element is in end
            if(front==NULL){
                cout<<"Queue already Empty!"<<endl;
            }
            Node *p=front;
            Node *q=front;
            while(p->next){
                q=p;
                p=p->next;
            }
            q->next=NULL;
            rear=q;
            delete p;
        }
        void Display(){
            Node *p=front;
            if(p==NULL){
                cout<<"Queue empty!"<<endl;
            }
            while(p){
                cout<<p->data<<endl;
                p=p->next;
            }
        }
        int isEmpty(){
            if(front==NULL){
                return 1;
            }else{
                return 0;
            }
        }
        int isFull(){
            Node *p=new Node();
            if(p==NULL){
                return 1;
            }else{
                return 0;
            }
        }
        Node* getFront(){
            return front;
        }
        Node* getRear(){
            return rear;
        }
        int getLength(){
            Node *p=front;
            int i=0;
            while(p){
                i++;
                p=p->next;
            }
            return i;
        }
};

int main(){
// element and priorities
    Queue q;

    q.Display();
    q.Enqueue(13);
    q.Display();
    q.Enqueue(9);
    q.Display();
    q.Enqueue(5);
    q.Display();
    q.Enqueue(11);
    q.Display();
    q.Enqueue(15);
    q.Display();

    q.Dequeue();
    q.Dequeue();
    q.Display();
}