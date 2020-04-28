#include<bits/stdc++.h>
using namespace std; 
//BUG

void ins(int A[],int n){ //n=size of array
    int temp;
    int i=n;
    temp=A[n];
    while(i>0&&temp>A[i/2]){ //O(logn)
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
    cout<<"Inserted : "<<temp<<endl;
}

void del(int A[],int n){ //n=size of array
    //we can only delete root element
    int x,i,j;
    x=A[0];
    A[0]=A[n-1];
    i=0; //i=1;
    j=1; //j=i*2;
    while(j<n){
        if(A[j+1]>A[j]){ //comparing children
            j=j+1;
        }
        if(A[i]<A[j]){ //comparing parent and child
            swap(A[j],A[i]);
            i=j;
            j=j*2;
        }
        else{
            break;
        }
    }
    A[n-1]=x;
    cout<<"Deleted : "<<x<<endl;
}

void create(int A[],int n){
    cout<<"Inserted : 10"<<endl;
    int i;
    for(i=1;i<n;i++){
        ins(A,i); //i=size of array at that point
    }
    // cout<<"Created Heap!"<<endl;
}

void disp(int A[],int n){ //n=array size  //level order display
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

void heapsort(int A[],int n){
    create(A,n);
    disp(A,n);
    for(int i=n-1;i>0;i--){
        del(A,i);
    }
    disp(A,n);
}

int main(){
    int A[]={10,20,30,25,40,35,45};

    create(A,7);
    // OR
    // heapsort(A,7); 

    disp(A,7);
    del(A,7);
    disp(A,6);
    del(A,6);
    disp(A,5);
    del(A,5);
    disp(A,4);
    del(A,4);
    disp(A,3);
    del(A,3);
    disp(A,2);
    del(A,2);
    disp(A,1);

}