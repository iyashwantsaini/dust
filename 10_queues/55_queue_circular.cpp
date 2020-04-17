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
            front=0;
            back=0;
            storage=NULL;
        }
        Queue(int s){
            this->size=s;
            this->storage=new int[s];
            for(int i=0;i<size;i++){
                storage[i]=0;
            }
            Display();
            front=0;
            back=0;
        }
        ~Queue(){
            delete storage;
        }
        void Enqueue(int num){
            if((back+1)%size==front){
                cout<<"Queue full!"<<endl;
            }else{
                if((front>back)&&(front-back)==2){ // to make sure that front index always remains empty
                    cout<<"Queue Full!"<<endl;
                }else{
                    back=(back+1)%size;
                    storage[back]=num;
                    cout<<"Added : "<<num<<" to index : "<<back<<endl;
                }
            }
        }
        void Dequeue(){
            if(back==front){
                cout<<"Queue already empty!"<<endl;
                return;
            }else{
                int x=storage[front];
                storage[front]=0;
                front=(front+1)%size;
                cout<<"Removed : "<<x<<" from index : "<<front-1<<endl;
            }
        }
        void Display(){
            cout<<"Elements : "<<endl;
            if(back==front){
                cout<<"Queue empty!"<<endl;
                return;
            }
            for(int i=0;i<size;i++){
                cout<<storage[i]<<endl;
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
    Queue q(5);

    q.isEmpty();
    
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();

    q.Dequeue();
    q.Dequeue();
    q.Display();

    q.Enqueue(50);
    q.Enqueue(60);
    q.Display();
    q.Enqueue(70);


    // cout<<q.getFirst()<<endl;
    // cout<<q.getLast()<<endl;
    // cout<<q.getLength()<<endl;
}