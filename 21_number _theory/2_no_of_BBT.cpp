// number of balanaced binary tress of height h
//  modulo not working here
#include<bits/stdc++.h>
using namespace std;

int BBT(int h){
    if(h==0||h==1){
        return 1;
    }
    else{
        int m=pow(10,9)+7;
        int x=BBT(h-1);
        int y=BBT(h-2);

        //modulo arithmetic
        long res1=(long)x*x;
        long res2=(long)x*y*2;

        int ans1=(int)(res1%m);
        int ans2=(int)(res2%m);

        int ans= (ans1+ans2)%m;
        return ans;
    }
}

int main(){
    int h;
    cout<<"Enter height : ";
    cin>>h;
    cout<<"Number of BBT : "<<BBT(h);
}