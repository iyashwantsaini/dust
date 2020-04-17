#include<bits/stdc++.h>
using namespace std;

// program for evaluating a postfix expression

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
        int isEmpty(){
            if(top==-1){
                cout<<"Empty!"<<endl;
                return 0;
            }else{
                cout<<"Not Empty!"<<endl;
                return 1;
            }
        }
        int isFull(){
            if(top==size-1){
                cout<<"stack full!"<<endl;
                return 1;
            }else{
                cout<<"stack not full!"<<endl;
                return 0;
            }
        }
};

int isOperant(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 1;
    }else{
        return 0;
    }
}

int getResult(int a, int b, char op){
    if(op=='+'){
        return b+a;
    }else if(op=='-'){
        return b-a;
    }else if(op=='*'){
        return b*a;
    }else if(op=='/'){
        return b/a;
    }
}

int main(){
    char postfix[]={'3','5','*','6','2','/','+','4','-','\0'};
    Stack s(strlen(postfix)+1);

    int x1=0;
    int x2=0;
    int result=0;
    int i=0;
    while(postfix[i]!='\0'){
        if(isOperant(postfix[i])){
            x2=s.pop();
            x1=s.pop();
            result=getResult(x2,x1,postfix[i]);
            s.push(result);
            i++;
        }else{
            s.push(postfix[i]-'0');
            i++;
        }
    }

    int ans=0;
    ans=s.pop();
    cout<<"Answer = "<<ans<<endl;
}

