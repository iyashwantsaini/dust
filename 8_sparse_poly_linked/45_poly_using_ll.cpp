#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int coeff;
        int exp;
        Node *next=NULL;
};

class Poly{
    private:
        Node *first;
    public:
        Poly(){
            first=NULL;
        }
        Poly(int a[][2],int terms){
            first=new Node();
            first->coeff=a[0][0];
            first->exp=a[0][1];

            Node *t;
            Node *last=first;
            for(int i=1;i<terms;i++){
                t=new Node;
                t->coeff=a[i][0];
                t->exp=a[i][1];

                last->next=t;
                last=t;
                t=t->next;
            }
        }
        ~Poly(){
            Node *p=first,*q;
            while(p){
                q=p;
                p=p->next;
                delete q;
            }
        }
        void DisplayPoly(){
            Node *p=first;
            while(p->next){
                cout<<p->coeff<<"*X^"<<p->exp<<" + ";
                p=p->next;
            }
            cout<<p->coeff<<"*X^"<<p->exp<<endl;
        }
        void EvaluatePoly(int x){
            Node *p=first;
            int sum;
            while(p){
                sum+=p->coeff*pow(x,p->exp);
                p=p->next;
            }
            cout<<"Ans : "<<sum<<endl;
        }
        void highestDegPoly(){
            Node *p=first;
            int high=-300;//-ve random
            while(p){
                if(high<p->exp){
                    high=p->exp;
                }
                p=p->next;
            }
            cout<<"Highest Degree : "<<high<<endl;
        }

};

int main(){
    cout<<"Enter number of terms : ";
    int t;
    cin>>t;

    int a[t][2];
    for(int i=0;i<t;i++){
        cin>>a[i][0]>>a[i][1];
    }

//     3
// 21 4
// 34 3
// 45 1

    Poly f(a,t);
    f.DisplayPoly();
    f.EvaluatePoly(3);
    f.highestDegPoly();
}