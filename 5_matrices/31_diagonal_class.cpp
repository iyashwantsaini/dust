#include<bits/stdc++.h>
using namespace std;

//a[i,j]=0 when i!=j

class Diagonal{
    private:
        int n;
        int *a;
    public:
    Diagonal(int n){
        this->n=n;
        a=new int[n];
    }
    ~Diagonal(){
        delete []a;
    }
    int length(){
       return this->n; 
    }
    void set(int i,int j,int x){
        if(i==j){
            a[i]=x;
        }
    }
    int get(int i,int j){
        if(i==j){
            return a[i];
        }
        return 0;
    }
    void display(){
        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
                cout<<get(i,j)<<" ";
        }
        cout<<"\n";
    }
    }
};

int main(){
    int n,num;
    cout<<"Enter size of diag matrix : ";
    cin>>n;
    Diagonal d(n);
    cout<<"Enter 5 diagonal elements with spaces : ";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j){
                cin>>num;
                d.set(i,j,num);
            }
        }
    }
    cout<<"You diagonal matrix : "<<endl;
    d.display();

}