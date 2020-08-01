#include<iostream>
#include<string>

using namespace std;
int main(){
    // string s="yash";
    // cout<<s;

    string s="yashwant";
    
    // string s1(s);
    // cout<<s1;

    string s1(s,2,4);
    cout<<s1;

    string s2=s.substr(2,4);
    // cout<<s2;
    // cout<<s2.length();

    if(s1.compare(s2)==0){
        cout<<"equal"<<endl;
    }else{
        cout<<"not eql"<<endl;
    }

}