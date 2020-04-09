#include<iostream>
#include<string>
using namespace std;

int main(){
    // string s ="how are you?";
    string s="hey where r               u going?";
    int words=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' '&&s[i-1]!=' '){
            words++;
        }
    }
    cout<<"no. of words : "<<words+1<<endl;
    return 0;
}