#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
//return forst non reperating charqcter

int main(){
    string s="aabbbcdde"; //here c
    map<char,int> m;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }

    map<char,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        if(it->second==1){
            cout<<it->first;
            break;
        }
    }
}