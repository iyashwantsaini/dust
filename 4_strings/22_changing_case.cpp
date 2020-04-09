#include<iostream>
#include<string>
using namespace std;

int main(){
    string s="yASH";
    cout<<"iNiTiAl string is : "<<s<<endl;
    for(int i=0;s[i]!='\0';i++){
        if(isupper(s[i])){
            s[i]=tolower(s[i]);
        }
        else{
            s[i]=toupper(s[i]);
        }
    }
    cout<<"ToGgLed string is : "<<s<<endl;
    return 0;
}