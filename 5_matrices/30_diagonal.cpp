#include<bits/stdc++.h>
using namespace std;

//a[i,j]=0 when i!=j

void setfn(int *a, int i, int j, int x){ //i=row,j=col,x=element
    if(i==j){
        a[i]=x;
    }
}

int getfn(int *a, int i, int j){
    if(i==j){
        return a[i];
    }
    return 0;
}

int main(){
    int a[5];
    cout<<"Enter 5 diagonal elements with spaces : ";
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j){
                cin>>a[i];
                setfn(a,i,j,a[i]);
            }
        }
    }
    cout<<"You diagonal matrix : "<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
                cout<<getfn(a,i,j)<<" ";
        }
        cout<<"\n";
    }

}