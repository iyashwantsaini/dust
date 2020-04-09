#include<bits/stdc++.h>
using namespace std;

//method1 -- two for loops
//method2 -- using bits - only if no duplicate letters are there
//method3 -- hash tables
void anagram(string a,string b){
    if(a.length()!=b.length()){
        cout<<"Not anagrams!";
        return;
    }
    int h[26]={};
    // for(int i=0;i<26;i++){
    //     cout<<h[i];
    // }
    for(int i=0;a[i]!='\0';i++){
        h[a[i]-97]+=1;
    }

    for(int i=0;b[i]!='\0';i++){
        h[b[i]-97]-=1;
    }

    for(int i=0;i<26;i++){
        if(h[i]>0){
            cout<<"Not anagrams!";
            return;
        }
    }
    cout<<"Anagrams";
    return;
}

int main(){
    string s="dom";
    string t="mod";
    anagram(s,t);    
}
