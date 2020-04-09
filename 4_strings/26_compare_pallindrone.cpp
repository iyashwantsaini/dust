#include<bits/stdc++.h>
using namespace std;

bool pallin(string &s){
    for(int i=0,j=s.length()-1;i<=j;i++,j--){
        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}

int main(){
    string s="madam";
    if(pallin(s)){
        cout<<"YES!";
    }else{
        cout<<"NO!";
    }

}
