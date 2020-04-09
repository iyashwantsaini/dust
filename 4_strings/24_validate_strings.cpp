#include<iostream>
#include<string>
using namespace std;

int validate(string s){
    for(int i=0;s[i]!='\0';i++){
        if(!(s[i]>=65&&s[i]<=90)&&!(s[i]>=97&&s[i]<=122)&&!(s[i]>=48&&s[i]<=57)){
            return 0;
        }
    }
    return 1;
}

int main(){
    // string s ="how are you";
    string s ="hhh";
    // cout<<validate(s);
    if(validate(s)){
        cout<<"String is valid!";
    }else{
        cout<<"String is invalid!";
    }
}