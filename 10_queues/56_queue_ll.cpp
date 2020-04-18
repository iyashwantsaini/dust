#include<bits/stdc++.h>
using namespace std;

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

int main(){
    Queue q;

    q.Display();
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Display();

    q.Dequeue();
    q.Dequeue();
    q.Display();

    cout<<q.getLength()<<endl;

}