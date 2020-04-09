#include<bits/stdc++.h>
using namespace std;

void swap(char *a,char *b){
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void permuteall(char *str,int l,int r){
    if(l==r){ //means that we have reached the leaf
        cout<<str<<endl;
    }
    else{
        for(int i=l;i<=r;i++){
            swap((str+l),(str+i)); //finding all possible combinations at a particular level of tree
            permuteall(str,l+1,r); //recursion to go to next level
            swap((str+l),(str+i)); //backtracking to get to right part of every branch of tree
        }
    }
    return;
}
int main() {
    char str[] = "ABCD";
    int l=0; //low
    int r=3; //high
    cout<<"All permutations of "<<str<<" : "<<endl;
    permuteall(str,l,r);
}