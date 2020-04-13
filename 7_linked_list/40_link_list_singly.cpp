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

    Node* getTail(){
        Node *p=first,*q;
        while(p){
            q=p;
            p=p->next;
        }
        return q;
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

    int CountNodes(){
        Node *bakup=first;
        int i=0;
        while(bakup){
            i++;
            bakup=bakup->next;
        }
        return i;
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

    //insert -- at head or in bw or at last
    void Insert(int num, int index){
        Node *t=new Node();
        t->data=num;
        t->next=NULL;

        Node *p=first;

        if(index==0){
            //at head
            t->next=first;
            first=t;
        }else if(index>=1&&index<CountNodes()){
            //in bw
            for(int i=0;i<index-1;i++){
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }else if(index==CountNodes()){
            //at end
            for(int i=0;i<index;i++){
                p=p->next;
            }
            p->next=t;
        }else{
            cout<<"Index out of bound!";
            return;
        }
    }

    //inserting in a sorted linked list
    void InsertInSorted(int num){
        Node *t=new Node();
        t->data=num;
        t->next=NULL;

        Node *p=first,*q=first;

        while (p->data<num){
            q=p;
            p=p->next;
        }
        t->next=q->next;
        q->next=t;
    }

    //deleting -- from head or bw or from end
    void DeleteNode(int index){
        Node*p=first,*q=first;

        if(index==0){
            first=first->next;
            delete p;
        }else if(index <CountNodes()){
            for(int i=0;i<index;i++){
                q=p;
                p=p->next;
            }
            q->next=p->next;
            delete p;
        }else if(index==CountNodes()){
            for(int i=0;i<index;i++){
                q=p;
                p=p->next;
            }
            q->next=NULL;
            delete p;
        }
    }

    //sortcheck
    void IsSorted(){
        Node *p=first,*q=first;
        // int x=p->data;
        while(p){
            if(p->data<q->data){
                cout<<"Not Sorted!";
                return;
            }
            q=p;
            p=p->next;
        }
        cout<<"Sorted!";
    }

    //removing duplicates 
    void RemDuplicates(){
        Node *p=first,*q;  //p in front, q in back
        q=p->next;
        while(p){
            if(p->data==q->data){
                q->next=p->next;
                delete p;
                p=q->next;
            }else{
                q=p;
                p=p->next;
            }
        }
    }

    //reversing ll -- using data
    void ReverseData(){
        Node *p=first;
        int a[CountNodes()];
        //copy
        for(int i=0;i<CountNodes();i++){
            a[i]=p->data;
            p=p->next;
        }
        p=first;
        //reversecopy
        for(int i=CountNodes()-1;i>=0;i--){
            p->data=a[i];
            p=p->next;
        }
    }

    //reverse --using links
    void ReverseLinks(){
        Node *p=first,*q=NULL,*r=NULL; // r -> q -> p
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        first=q;
    }

    //reverse --recursive
    void ReverseRecursive(Node *q, Node *p){
        if (first == NULL || first->next == NULL){
            return;
        }
        if(p){
            ReverseRecursive(p,p->next);
            p->next=q;
        }else{
            first=q;
        }
    }

    //concatination
    void Concatinate(Node *newnode){
        Node *p=first,*q;
        while(p){
            q=p;
            p=p->next;
        }
        q->next=newnode;
    }

    //merging --2 sorted linked lists are merged
    void MergeSortedLists(Node * newnode){
        Node *f=getHead();
        Node *s=newnode;
        Node *third,*last;

        if(f->data<s->data){
            third=f;
            last=f;
            f=f->next;
            last->next=NULL;
        }else{
            third=s;
            last=s;
            s=s->next;
            last->next=NULL;
        }
        while(f&&s){
            if(f->data<s->data){
                last->next=f;
                last=f;
                f=f->next;
                last->next=NULL;
            }else{
                last->next=s;
                last=s;
                s=s->next;
                last->next=NULL;
            }
        }
        if(f){
            last->next=f;
        }
        if(s){
            last->next=s;
        }
    }

    // any loop or not
    void LoopCheck(){
        Node *p=first,*q=first;
        while(p&&q){
            p=p->next;
            q=q->next;
            if(q!=NULL) q=q->next;

            if(p==q){
                cout<<"Loop Present";
                return;
            }
        }
        cout<<"No loop!";
    }

};

int main(){
    int a[]={1,2,3,40,51,53,63,65,69,70,78};
    int size = sizeof(a)/sizeof(a[0]);
    LinkedList ll(a,size);

    // ll.RDisplay(ll.getHead());
    // ll.Display();
    // cout<<ll.CountNodes(); //length
    // ll.SumNodes();
    // ll.MaxElement();

    // ll.LSearch(4);
    // ll.RSearch(ll.getHead(),5);
    
    // ll.Display();
    // ll.ImpLSearch(4);
    // ll.Display();

    // ll.Insert(45,0); //head
    // ll.Display();
    // ll.Insert(46,4); //between
    // ll.Display();
    // ll.Insert(34,ll.CountNodes()-1);  //end
    // ll.Display();

    // ll.Display();
    // ll.InsertInSorted(61);
    // ll.Display();

    // ll.Display();
    // ll.DeleteNode(0); //from start
    // ll.Display();
    // ll.DeleteNode(4); //from mid
    // ll.Display();
    // ll.DeleteNode(ll.CountNodes()-1); //from end
    // ll.Display();

    // ll.IsSorted();

    // ll.Display();
    // ll.RemDuplicates();
    // ll.Display();

    // ll.Display();
    // ll.ReverseData();
    // ll.Display();
    // ll.ReverseLinks();
    // ll.Display();
    // ll.ReverseRecursive(NULL,ll.getHead());
    // ll.Display();

    // int a2[]={1,2,3,40,50,50,60,60,60,70,70};
    // int size2 = sizeof(a2)/sizeof(a2[0]);
    // LinkedList ll2(a2,size2);
    // ll2.Display();
    // ll.Concatinate(ll2.getHead());
    // ll.Display();

    // int a2[]={23,53,56,59,71,82,301,401};
    // int size2 = sizeof(a2)/sizeof(a2[0]);
    // LinkedList ll2(a2,size2);
    // ll.MergeSortedLists(ll2.getHead());
    // ll.Display();

    // ll.LoopCheck();

}