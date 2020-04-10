#include<bits/stdc++.h>
using namespace std;

// 3 diagonal are non zero in tridiagonal
// 1. main digonal --i-j=0
// 2. lower diagonal -- i-j=1
// 3. upper diagonal -- i-j=-1

// so, if |i-j|<=1 then non zero

// totol non zero : 3n-2

// first store lower, then main, then upper diagonal
// lower : if i-j=1 : index: i-2
// main : if i-j=0 : index: n-1+i-1
// upper : if i-j=-1 : index: 2n-1+i-1

// "square band matrix" : has more no. of diagonals that are non zero

class TriDiagonal{
    private:
        int n;
        int *a;
    public:
    TriDiagonal(int n){
        this->n=n;
        a=new int[(3*n)-2];
    }
    ~TriDiagonal(){
        delete []a;
    }
    int length(){
       return ((3*this->n)-2)-1; 
    }
    void set(int i,int j,int x){
        if(i-j==1){
            a[i-2]=x;
        }else if(i-j==0){
            a[n-1+i-1]=x;
        }else if(i-j==-1){
            a[2*n-1+i-1]=x;
        }
    }
    int get(int i,int j){
        if(i-j==1){
            return a[i-2];
        }else if(i-j==0){
            return a[n-1+i-1];
        }else if(i-j==-1){
            return a[2*n-1+i-1];
        }
        return 0;
    }
    void display(){
        for(int i=1;i<=this->n;i++){
            for(int j=1;j<=this->n;j++){
                if(i-j==1){
                    cout<<a[i-2]<<" | ";
                }else if(i-j==0){
                    cout<<a[n-1+i-1]<<" | ";
                }else if(i-j==-1){
                    cout<<a[2*n-1+i-1]<<" | ";
                }
                else{
                    cout<<"0 | ";
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
    TriDiagonal d(n);
    cout<<"Enter elements with spaces : "<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                if(abs(i-j)<=1){
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