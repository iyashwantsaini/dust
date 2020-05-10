// log(n) method of calculating big powers 
// modular exponentiation recursive

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int modexp(int a,int b){
    if(b==0){
        return 1;
    }else if(b%2==0){
        // even
        return (modexp(a*a%MOD,b/2))%MOD; 
    }else{
        // odd
        return ((a%MOD)*modexp(a*a%MOD,(b-1)/2))%MOD;
    }
}

int main(){
    int a=2;
    int b=31;
    cout<<modexp(a,b);
}