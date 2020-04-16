#include<bits/stdc++.h>
using namespace std;

// eg. (a+) b(+) will also bet true here -- as its only balance check

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
        int pop(){
            if(top<0){
                cout<<"Stack empty already!"<<endl;
                return 0;
            }
            int bakup=s[top];
            top=top-1;
            cout<<"Popped : "<<bakup<<" from index : "<<top+1<<endl;
            return bakup;
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
        bool isEmpty(){
            if(top==-1){
                return 1;
            }else{
                return 0;
            }
        }
        bool isFull(){
            if(top==size-1){
                return 1;
            }else{
                return 0;
            }
        }
};

int main(){
    char a[]="{[(hello)]}"; // parenthesis are correct!
    // char a[]="{[(hello}]}"; // parenthesis are incorrect!

    int size=sizeof(a)/sizeof(a[0]);
    // for(int i=0;i<size;i++){
    //     printf("%c",a[i]);
    // }
    int got;
    Stack s(size);
    for(int i=0;i<size;i++){
        if(a[i]=='('||a[i]=='['||a[i]=='{'){
            s.push(a[i]);
        }else if(a[i]==')'||a[i]==']'||a[i]=='}'){
            got=s.pop();
            if(got=='('&&a[i]==')'){
                continue;
            }else if(got=='['&&a[i]==']'){
                continue;
            }else if(got=='{'&&a[i]=='}'){
                continue;
            }else{
                cout<<"Wrong Pattern!"<<endl;
                break;
            }
        }
    }

    if(s.isEmpty()){
        cout<<"Parenthesis are correct!";
    }else{
        cout<<"Parenthesis are not correct!";
    }
    
}