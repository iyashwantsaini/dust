#include<bits/stdc++.h>
using namespace std;

// elements in a diagonal are same
// m[i,j]==m[i-1,j-1] *
// so its sufficient to store a row of elements and a column of elements --2n-1

// first store row elements then store column elements
// if i<=j--(upper triag) -> index=j-i
// if i>j--(lower triag) -> index=n+i-j-1

class Toeplitz{
    private:
        int n;
        int *a;
    public:
    Toeplitz(int n){
        this->n=n;
        a=new int[n*(n+1)/2];
    }
    ~Toeplitz(){
        delete []a;
    }
    int length(){
       return (2*this->n)-1; 
    }
    void set(int i,int j,int x){
        if(i<=j){
            a[j-i]=x;
        }else if(i>j){
            a[n+i-j-1]=x;
        }
    }
    int get(int i,int j){
        if(i<=j){
            return a[j-i];
        }else if(i>j){
            return a[n+i-j-1];
        }
        return 0;
    }
    void display(){
        // for(int i=0;i<2*n-1;i++){
        //     cout<<a[i];
        // }
        for(int i=1;i<=this->n;i++){
        for(int j=1;j<=this->n;j++){
                if(i<=j){
                    cout<<a[j-i]<<" | ";
                }else{
                    cout<<a[n+i-j-1]<<" | ";
                }
        }
        cout<<"\n";
    }
    }
};

int main(){
    int n,num;
    cout<<"Enter size of diag matrix : ";
    cin>>n;
    Toeplitz d(n);
    cout<<"Enter elements with spaces : "<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                if(i==1||j==1){
                cout<<"row :"<<i<<" | ";
                cout<<"col :"<<j<<" ";
                cin>>num;
                d.set(i,j,num);
                }
        }
    }
    cout<<"You matrix : "<<endl;
    d.display();
}