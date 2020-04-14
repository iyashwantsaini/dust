#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
       Node *prev;
       int data;
       Node *next;
};

class CircularDoublyLL{
    private:
        Node *first;
    public:
        
        CircularDoublyLL(){
            first=NULL;
        }
        
        CircularDoublyLL(int *a, int size){
            Node *t, *back;
            first=new Node();
            first->data=a[0];
            first->prev=first->next=first;

            back=first;
            for(int i=1;i<size;i++){
                t=new Node();
                t->data=a[i];
                t->prev=back;
                t->next=back->next;
                back->next=t;
                back=t;
            }
            back->next=first;
            first->prev=back;
        }
        
        ~CircularDoublyLL(){
            Node *p, *q;
            while(p){
                q=p;
                p=p->next;
                delete q;
            }
        }
        
        Node* getHead(){
            return first;
        }

        Node* getTail(){
            return first->prev;
        }
        
        int getLength(){
            Node *p=first;
            int i=0;
            do{
                i++;
                p=p->next;
            }while(p!=first);
            return i;
        }

        void DisplayLL(){
            Node *p=first;
            do{
                cout<<p->data<<" ";
                p=p->next;
            }while(p!=first);
            cout<<"\n";
        }

        void InsertNode(int num, int index){
            Node *t=new Node();
            t->data=num;
            t->next=t->prev=NULL;

            if(index==0){
                //at front
                t->prev=first->prev;
                first->prev->next=t;
                first->prev=t;
                t->next=first;
                first=t;
            }else if(index<getLength()-1){
                //at mid
                Node *p=first,*q=first;
                for(int i=0;i<index;i++){
                    q=p;
                    p=p->next;
                }
                q->next=t;
                t->prev=q;
                t->next=p;
                p->prev=t;
            }else if(index==getLength()-1){
                //at end
                Node *p=first;
                t->prev=first->prev;
                t->next=first;
                p->prev->next=t;
                first->prev=t;
            }else{
                //none
                cout<<"Index out of bound!"<<endl;
                return;
            }
        }

        void DeleteNode(int index){

            if(index==0){
                //first
                Node *p=first;
                p->next->prev=p->prev;
                p->prev->next=p->next;
                first=p->next;
                delete p;
            }else if(index<getLength()-1){
                //mid
                Node *p=first,*q=first;
                for(int i=0;i<index;i++){
                    q=p;
                    p=p->next;
                }
                q->next=p->next;
                p->next->prev=q;
                delete p;
            }else if(index==getLength()-1){
                //end
                Node *p=first,*q=first;
                for(int i=0;i<index;i++){
                    q=p;
                    p=p->next;
                }
                q->next=p->next;
                p->next->prev=q;
                delete p;
            }else{
                cout<<"Index Out of bound!"<<endl;
                return;
            }
        }

        void ReverseLL(){
            Node *t=getTail();

            Node *p=first;
            Node *temp;

            do{
                temp=p->next;
                p->next=p->prev;
                p->prev=temp;
                p=p->prev;
            }while(p!=first);
            first=t;
        }

};

int main(){
    int arr[]={1,2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    CircularDoublyLL dll(arr,size);

    // dll.DisplayLL();
    // cout<<dll.getLength()<<endl;

    // cout<<dll.getHead()->data<<endl;
    // cout<<dll.getTail()->data<<endl;
    
    // dll.DisplayLL();
    // dll.InsertNode(100,3);
    // dll.DisplayLL();
    // dll.InsertNode(67,0);
    // dll.DisplayLL();
    // dll.InsertNode(90,dll.getLength());
    // dll.DisplayLL();
    // dll.InsertNode(99,dll.getLength()-1);
    // dll.DisplayLL();

    // dll.DisplayLL();
    // dll.DeleteNode(0);
    // dll.DisplayLL();
    // dll.DeleteNode(3);
    // dll.DisplayLL();
    // dll.DeleteNode(dll.getLength()-1);
    // dll.DisplayLL();

    // dll.DisplayLL();
    // dll.ReverseLL();
    // dll.DisplayLL();

}