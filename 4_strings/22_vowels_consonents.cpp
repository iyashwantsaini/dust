#include<iostream>
#include<string>
using namespace std;

int main(){
    string s ="how are you?";
    int vov=0,cons=0;
    for(int i=0;s[i]!='\0';i++){
        if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')||(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')){
            vov++;
        }
        else if((int(s[i])>=65&&int(s[i])<=90)||(int(s[i])>=97&&int(s[i])<=122)){
            cons++;
        }
    }
    cout<<"no. of vowels : "<<vov<<endl;
    cout<<"np. of consonents : "<<cons<<endl;
    return 0;
}