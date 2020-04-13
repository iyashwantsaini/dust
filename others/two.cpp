#include<bits/stdc++.h>
using namespace std;

void printstr(int len, int subsize, int uniq){ 
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; 

    char *res=new char[len];
    
    for (int i = 0; i < len; i++){  
        res[i]= alphabet[i];
    }
    if(uniq==1&&subsize==1){
        cout<<res<<endl;
        return;   
    }
    if(uniq==1&&subsize==len){
        for(int i=0;i<len;i++){
            res[i]='a';
        }
        cout<<res<<endl;
        return;   
    }
    for (int i=0;i<(len-subsize)-1;i++){
        for(int k=i;k<subsize&&k<len-i;k++){
            for(int j=subsize+i-1,m=i;(j>i+uniq-1)&&j<len;j--,m++){
                res[j]=res[m];
            }
        }
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    int arr[t][3];
    for(int i=0;i<t;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
        cin>>arr[i][2];
    }

    for(int i=0;i<t;i++){
        printstr(arr[i][0],arr[i][1],arr[i][2]);
    }
}