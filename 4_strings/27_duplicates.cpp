#include<bits/stdc++.h>
using namespace std;

// using comparision
void duplicatescomp(string &s){
    // cout<<"entered";
    for(int i=0;s[i]!='\0';i++){
        for(int j=i+1;s[j]!='\0';j++){
            if(s[i]==s[j]){
                cout<<"Duplicate of "<<s[i]<<" found at index "<<j<<endl;
            }
        }
    }
}

//using hashtables
void duplicateshash(string &s){
    //a-97||z-122
    int arr[26];
    for(int i=0;i<25;i++){
        arr[i]=0;
    }
    
    for(int i=0;s[i]!='\0';i++){
        arr[s[i]-97]+=1;
    }
    
    for(int i=0;i<=25;i++){
        if(arr[i]>=1){
            cout<<"char := "<<char(i+97)<<" | nooftimes := "<<arr[i]<<endl;
        }
    }
}

// using bitwise op - masking & merging
void duplicatesbitwise(string &s){
    int x=0,i=0;
    long int H=0; 
    for(i=0;s[i]!='\0';i++){
        x=1;
        x=x<<s[i]-97;
        if((H&x)>0){
            cout<<s[i]<<" is having a duplicate!"<<endl;
        }else{
            H=H|x;
        }
    }
}

int main(){
    string s="madam";
    duplicatescomp(s);
    duplicateshash(s);
    duplicatesbitwise(s);
}
