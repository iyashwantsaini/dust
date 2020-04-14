#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class circularll{
    private:
        Node *first;
    public:
    circularll(){
        first=NULL;
    }
    circularll(int *a, int size){
        Node *t,*last;
        
        first=new Node();
        first->data=a[0];
        first->next=first;
        last=first;

        for(int i=1;i<size;i++){
            t=new Node();
            t->data=a[i];
            last->next=t;
            t->next=first;
            last=t;
        }
    }
    ~circularll(){
        Node *p=first;
        do{
            first=first->next;
            delete p;
            p=first;
        }while(p!=first);

    }
    Node* getHead(){
        return first;
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

    //iterative display
    void iterDisplay(){
        Node *p=first;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=first);
        cout<<"\n";
    }

    //recursive display
    void recDisplay(Node *p){
        static int flag=0;
        if(p!=first||flag==0){
            flag=1;
            cout<<p->data<<" ";
            recDisplay(p->next);
        }
        flag=0;
        cout<<"\n";
    }

    //insert
    void insertCLL(int num, int index){
        Node *t=new Node(); 
        t->data=num;
        
        Node *p;        

        if(index==0){
            //insert before head
            if(first==NULL){ //if its the forst node
                first=t;
                first->next=first;
            }else{
                while(p->next!=first){
                    p=p->next;
                }
                p->next=t;
                t->next=first;
                first=t;
            }
        }else if(index<getLength()){
            Node *link=first;
            //insert in mid
            p=first;
            for(int i=0;i<index-1;i++){
                p=p->next;
            }
            link=p->next;
            p->next=t;
            t->next=link;

        }else{
            cout<<"Out of bounds!";
            return;
        }

    }

    //delete node
    void deleteNode(int index){
        if(index<0||index>=getLength()){
            cout<<"Out of bound!"<<endl;
            return;
        }
        Node *p=first,*q=first;
        if(index==0){
            while(p->next!=first){
                p=p->next;
            }
            p->next=q->next;
            first=q->next;
            delete q;
        }else{
            for(int i=0;i<index;i++){
                q=p;
                p=p->next;
            }
            q->next=p->next;
            delete p;
        }
    }



};


int main(){
    int arr[]={1,3,5,7,8,9,21};
    int size=sizeof(arr)/sizeof(arr[0]);
    circularll cll(arr,size);

    // cout<<cll.getLength();

    // cll.iterDisplay();
    // cll.recDisplay(cll.getHead());

    // cll.iterDisplay();
    // cll.insertCLL(6,3);
    // cll.iterDisplay();
    // cll.insertCLL(90,0);
    // cll.iterDisplay();

    // cll.iterDisplay();
    // cll.deleteNode(1);
    // cll.iterDisplay();
    // cll.deleteNode(6);
    // cll.iterDisplay();
    // cll.deleteNode(5);
    // cll.iterDisplay();
    // cll.deleteNode(0);
    // cll.iterDisplay();


}