#include <bits/stdc++.h> 
using namespace std; 
// geek4geek
void reverseStr(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
}
// myfn
string revfn(string b){
    string a=b;
    for(int i=0,j=b.length()-1;(b[i]!='\0')&&(j>=0);i++,j--){
        a[j]=b[i];
    }
    return a;
}

int main() 
{ 
    string str = "yash"; 
    // reverseStr(str); 
    string newstr=revfn(str);
    cout<<newstr;
    // cout << "reverse is : "<<str; 
    return 0; 
} 