#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int back;
        int *storage;
    public:
        Queue(){
            size=0;
            front=-1;
            back=-1;
            storage=NULL;
        }
        Queue(int s){
            this->size=s;
            this->storage=new int[s];
            front=-1;
            back=-1;
        }
        ~Queue(){
            delete storage;
        }
        void Enqueue(int num){
            if(back==size-1){
                cout<<"Queue already full!"<<endl;
                return;
            }
            back+=1;
            storage[back]=num;
            cout<<"Added : "<<num<<" to index : "<<back<<endl;
        }
        void Dequeue(){
            if(back==front){
                cout<<"Queue already empty!"<<endl;
                return;
            }
            front+=1;
        }
        void Display(){
            if(back==front){
                cout<<"Queue empty!"<<endl;
                return;
            }
            int f=front+1;
            while(f!=back+1){
                cout<<storage[f]<<endl;
                f++;
            }
        }
        int isEmpty(){
            if(back==front){
                cout<<"Queue empty!"<<endl;
                return 1;
            }else{
                return 0;
            }
        }
        int isFull(){
            if(back==size-1){
                cout<<"Queue full!"<<endl;
                return 1;
            }else{
                return 0;
            }
        }
        int getLast(){
            if(back==front){
                cout<<"Queue empty!"<<endl;
                return 0;
            }
            return storage[back];
        }
        int getFirst(){
            if(back==front){
                cout<<"Queue empty!"<<endl;
                return 0;
            }
            return storage[front+1];
        }
        int getLength(){
            return back-front;
        }
};

int main(){
    Queue q(20);

    q.isEmpty();
    
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Display();

    q.Dequeue();
    q.Dequeue();
    q.Display();

    cout<<q.getFirst()<<endl;
    cout<<q.getLast()<<endl;
    cout<<q.getLength()<<endl;
}