#include<bits/stdc++.h>
using namespace std;

// we will do all ops on head - as it takes O(1) time in insertion and deletion

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
        void pop(){
            if(top==NULL){
                cout<<"Stack is empty!"<<endl;
                return;
            }
            Node *t=top;
            int x=top->data;
            top=top->next;
            delete t;
            cout<<"Popped : "<<x<<endl;
        }
        void peek(int index){
            Node *p=top;
            for(int i=0;i<index-1;i++){
                p=p->next;
            }
            cout<<"Element at index : "<<index<<" is : "<<p->data<<endl;
        }
        int getLength(){
            Node *t=top;
            int i=0;
            while(t){
                i++;
                t=t->next;
            }
            return i;
        }
        int getTopElement(){
            return top->data;
        }
        void isEmpty(){
            if(top==NULL){
                cout<<"Empty!"<<endl;
                return;
            }
            cout<<"Not Empty"<<endl;
        }

        // full only if heap is full , so try creating a new node
        void isFull(){
            Node *t=new Node();
            if(t==NULL){
                cout<<"Full!"<<endl;
                return;
            }
            cout<<"Not Full!"<<endl;
        }
};

int main(){

    Stack s;
    s.isEmpty();
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    cout<<s.getLength()<<endl;
    s.pop();
    s.pop();
    cout<<s.getLength()<<endl;
    cout<<s.getTopElement()<<endl;
    s.isEmpty();
    s.isFull();
    s.peek(1);
}