#include<bits/stdc++.h>
using namespace std;

//a[i,j]=0 when i<j
//a[i,j]!=0 when i>=j
//n*(n+1)/2 elements are non zero
//n*(n-1)/2 elements are zero

// accessing non zero elements
// row major --  a[i,j] = [i*(i-1)/2 ]+j-1 -- used in this program
// col major --  a[i,j] = {n(j-1)-[(j-2)(j-1)/2]} + i-j 

class LowerTriag{
    private:
        int n;
        int *a;
    public:
    LowerTriag(int n){
        this->n=n;
        a=new int[n*(n+1)/2];
    }
    ~LowerTriag(){
        delete []a;
    }
    int length(){
       return this->n*(n+1)/2; 
    }
    void set(int i,int j,int x){
        if(i>=j){
            a[(i*(i-1)/2) +j-1]=x;
        }
    }
    int get(int i,int j){
        if(i>=j){
            return a[(i*(i-1)/2) +j-1];
        }
        return 0;
    }
    void display(){
        for(int i=1;i<=this->n;i++){
        for(int j=1;j<=this->n;j++){
                if(i>=j){
                    cout<<a[(i*(i-1)/2)+j-1]<<" ";
                }else{
                    cout<<"0 ";
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
    LowerTriag d(n);
    cout<<"Enter elements with spaces : "<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){
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