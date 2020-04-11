#include<bits/stdc++.h>
using namespace std;

struct term{
    double coeff;
    double exp; 
};
struct polynomial{
    int n;
    term *t;
};
void createPoly(polynomial *p){
    cout<<"Enter terms as COEFF | POWER "<<endl;
    for(int i=0;i<p->n;i++){
        cout<<"term : "<<i+1<<"  |  ";
        cin>>p->t[i].coeff>>p->t[i].exp;
    }
}
void evaluatePoly(polynomial *p, double x){
    double sum=0;
    for (int i=0;i<p->n;i++){
        sum += p->t[i].coeff * pow(x,p->t[i].exp);
    }
    cout<<"ans : "<<sum<<endl;
}
void displayPoly(polynomial *p){
    int i{};
    cout<<"Poly: ";
    for(i=0;i<(p->n)-1;i++){
        cout<<p->t[i].coeff<<"X^"<<p->t[i].exp<<" + "; 
    }
    // last element print without "+"
    cout<<p->t[i].coeff<<"X^"<<p->t[i].exp; 
    cout<<"\n";
}
void additionPoly(polynomial *p1, polynomial *p2){
    polynomial p3;
    int x=0, y=0, z=0;
    p3.n=p1->n+p2->n;
    p3.t=new term[p3.n];

    while(x<p1->n&&y<p2->n){
        if(p1->t[x].exp>p2->t[y].exp){
            p3.t[z++]=p1->t[x++];
        }else if(p1->t[x].exp<p2->t[y].exp){
            p3.t[z++]=p2->t[y++];
        }else{
            p3.t[z]=p1->t[x++];
            p3.t[z++].coeff+=p2->t[y++].coeff;
        }
    }
    // copy remaining terms of longer array
    for(;x<p1->n;x++){
        p3.t[z++]=p1->t[x];
    }
    for(;y<p2->n;y++){
        p3.t[z++]=p2->t[y];
    }
    p3.n=z;
    displayPoly(&p3);
}

int main(){
    //poly1
    cout<<"Poly 1 : "<<endl;
    cout<<"Enter number of terms : ";
    int n1;
    cin>>n1;
    polynomial p1;
    p1.n=n1;
    p1.t=new term[n1];
    createPoly(&p1);
    // displayPoly(&p1);
    //poly2
    cout<<"Poly 2 : "<<endl;
    cout<<"Enter number of terms : ";
    int n2;
    cin>>n2;
    polynomial p2;
    p2.n=n2;
    p2.t=new term[n2];
    createPoly(&p2);
    // displayPoly(&p2);

    //evaluate
    // cout<<"Poly 1 : ";
    // evaluatePoly(&p1,5);
    // cout<<"Poly 2 : ";
    // evaluatePoly(&p2,10);

    //addn
    additionPoly(&p1,&p2);
}