#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *s;
    public:
        Stack(){
            top=-1;
        }
        Stack(int size){
            this->size=size;
            s=new int[size];
            top=-1;
        }
        ~Stack(){
            delete s;
        }
        void push(int x){
            if(top>=size-1){
                cout<<"Stack Full!"<<endl;
                return;
            }
            top=top+1;
            s[top]=x;
            cout<<"Pushed : "<<x<<" at index : "<<top<<endl;
        }
        void pop(){
            if(top<=0){
                cout<<"Stack empty already!"<<endl;
                return;
            }
            int bakup=s[top];
            top=top-1;
            cout<<"Popped : "<<bakup<<" from index : "<<top+1<<endl;
        }
        void peek(int index){
            if(index<=0||index>top){
                cout<<"Invalid index!"<<endl;
                return;
            }
            int bakup=top;
            while(bakup!=index){
                bakup--;
            }
            cout<<"Element at index : "<<index<<" is : "<<s[bakup]<<endl;
        }
        int getTopIndex(){
            return top;
        }
        int getTopElement(){
           return s[top]; 
        }
        void isEmpty(){
            if(top==-1){
                cout<<"Empty!"<<endl;
            }else{
                cout<<"Not Empty!"<<endl;
            }
        }
        void isFull(){
            if(top==size-1){
                cout<<"stack full!"<<endl;
            }else{
                cout<<"stack not full!"<<endl;
            }
        }
};

int main(){
    cout<<"Enter size of stack : ";
    int size;
    cin>>size;
    Stack s(size);
    s.push(100);
    s.push(200);
    s.push(300);
    s.pop();
    cout<<s.getTopElement()<<endl;
    cout<<s.getTopIndex()<<endl;
    s.isEmpty();
    s.isFull();
    s.peek(1);
}