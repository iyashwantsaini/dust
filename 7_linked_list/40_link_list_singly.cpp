#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *first; // head pointer
    public:
    LinkedList(){
        first=NULL;
    }
    LinkedList(int *a, int size){
        Node *last, *t; // t=for creating new nodes | last=for keeping track

        first=new Node(); // creating head
        first->data=a[0];
        first->next=NULL;
        last=first;

        for(int i=1;i<size;i++){
            t=new Node();
            t->data=a[i];
            t->next=NULL;

            last->next=t;
            last=t;
        }
    }
    ~LinkedList(){
        Node *del=first;
        while(first){
            first=first->next; //first moves forward
            delete del;
            del=first;
        }
    }

    Node* getHead(){
        Node *p=first;
        return p;
    }

    //iterative_function
    void Display(){
        cout<<"Linked List : ";
        Node *iter=first;

        while(iter){
            cout<<iter->data<<" ";
            iter=iter->next;
        }
        cout<<"\n";
    }

    //recursive function
    void RDisplay(Node *p){
        while(p){
            cout<<p->data<<" ";
            return RDisplay(p->next);
        }
        cout<<"\n";
    }

    void CountNodes(){
        Node *bakup=first;
        int i=0;
        while(bakup){
            i++;
            bakup=bakup->next;
        }
        cout<<"No. of nodes : "<<i<<endl;
    }

    //sum of all data elements
    void SumNodes(){
        Node *bakup=first;
        int sum=0;
        while(bakup){
            sum=sum+bakup->data;
            bakup=bakup->next;
        }
        cout<<"Sum of node data : "<<sum<<endl;
    }

    void MaxElement(){
        Node *bakup=first;
        int maxel=-1;
        while(bakup){
            if(maxel<bakup->data){
                maxel=bakup->data;
            }
            bakup=bakup->next;
        }
        cout<<"Max Element : "<<maxel<<endl;
    }

    //linear search
    void LSearch(int key){
        Node *bakup=first;
        int i=0;
        while(bakup){
            if(key==bakup->data){
                cout<<"Key found at index : "<<i;
                return;
            }
            i++;
            bakup=bakup->next;
        }
    }

    //recursive linear search
    void RSearch(Node *p, int key){
        static int irs=0;
        if(!p){
            return;
        }
        if(key==p->data){
            cout<<"Key found at index : "<<irs;
            return;
        }
        irs++;
        return RSearch(p->next, key);
    }

    //improved linear search -- go to head
    void ImpLSearch(int key){
        Node *p,*q;
        p=first;
        while(p){
            if(p->data==key){
                q->next=p->next;
                p->next=first;
                first=p;
            }
            q=p;
            p=p->next;
        }
    }



};

int main(){
    int a[]={1,2,3,4,5,6,7};
    int size = sizeof(a)/sizeof(a[0]);
    LinkedList ll(a,size);

    ll.RDisplay(ll.getHead());
    ll.Display();
    ll.CountNodes(); //length
    ll.SumNodes();
    ll.MaxElement();
    ll.LSearch(4);
    ll.RSearch(ll.getHead(),5);
    
    // ll.Display();
    // ll.ImpLSearch(4);
    // ll.Display();



}