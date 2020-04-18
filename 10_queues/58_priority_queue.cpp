#include <bits/stdc++.h>
using namespace std;

// both front and rear can do insertion and deletion
// in this case we take 3 priorities : 1,2,3 : 1 = highest, 3 = lowest

class Node{
    public:
        char data;
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
            if(front==NULL){
                front=t;
                rear=t;
                cout<<"Enqueued "<<t->data<<" at index 0"<<endl;
            }else{
                rear->next=t;
                rear=t;
                cout<<"Enqueued "<<t->data<<" at index "<<getLength()-1<<endl;
            }
        }
        void Dequeue(){
            if(front==NULL){
                cout<<"Queue already Empty!"<<endl;
            }
            Node *p=front;
            front=front->next;
            cout<<"Dequeued "<<p->data<<" from index 0"<<endl;
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

class PriorQueue{
    private:
        Queue *q1,*q2,*q3;
    public:
        PriorQueue(){
            q1=new Queue(); //priority 1 :highest
            q2=new Queue(); //priority 2
            q3=new Queue(); //priority 3 :least
        }
        ~PriorQueue(){
            delete q1;
            delete q2;
            delete q3;
        }
        void enq(char x, int prior){
            if(prior==1){
                q1->Enqueue(x);
                cout<<"Equeued to q1"<<endl;
            }else if(prior==2){
                q2->Enqueue(x);
                cout<<"Equeued to q2"<<endl;
            }else if(prior==3){
                q3->Enqueue(x);
                cout<<"Equeued to q3"<<endl;
            }
        }
        void deq(){
            if(!q1->isEmpty()){
                q1->Dequeue();
                cout<<"Dequeued from q1"<<endl;
            }else if(!q2->isEmpty()){
                cout<<"Q1 is empty!"<<endl;
                q2->Dequeue();
                cout<<"Dequeued from q2"<<endl;
            }else if(!q2->isEmpty()){
                cout<<"Q2 is empty!"<<endl;
                q3->Dequeue();
                cout<<"Dequeued from q3"<<endl;
            }else{
                cout<<"All queues are empty!"<<endl;
            }
        }
};

int main(){
// element and priorities
    PriorQueue pq;
    
    pq.enq('a',1);
    pq.enq('b',1);
    pq.enq('c',2);
    pq.enq('d',3);
    pq.enq('e',2);
    pq.enq('f',1);
    pq.enq('g',2);
    pq.enq('h',3);
    pq.enq('i',2);
    pq.enq('j',2);

    pq.deq();
    pq.deq();
    pq.deq();
    pq.deq();
    pq.deq();
    pq.deq();
    pq.deq();
    pq.deq();
    pq.deq();
    pq.deq();

}