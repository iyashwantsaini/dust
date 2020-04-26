#include<bits/stdc++.h>
using namespace std;
#define SIZE 10

int hashfn(int key){
    return key%SIZE;
}

int probe(int HT[], int key){
    int index=hashfn(key);
    int i=0;
    while(HT[index+i]%SIZE!=0){ //probing function
        i++;
    }
    return (index+i)%SIZE;
}

void insert(int HT[],int key){
    int index=hashfn(key);
    if(HT[index]!=0){ //already occupied
        index=probe(HT,key);
    }
    HT[index]=key;
    cout<<"Inserted "<<key<<" at index "<<index<<endl;
}

int search(int HT[], int key){
    int index=hashfn(key);
    int i=0;
    while(HT[(index+i)%SIZE]!=key){ //finding index from probing formula
        i++;
    }
    cout<<"Key : "<<key<<" found at index : "<<(index+i)%SIZE<<endl;
    return (index+i)%SIZE;
}

void display(int HT[]){
    for(int i=0;i<SIZE;i++){
        cout<<"Index : "<<i<<" Value : "<<HT[i]<<endl;
    }
}

int main(){
    int HT[10]={};
    insert(HT,12);
    display(HT);
    insert(HT,25);
    display(HT);
    insert(HT,35);
    display(HT);
    insert(HT,26);
    display(HT);

    search(HT,25);
    search(HT,35);

    return 0;
}