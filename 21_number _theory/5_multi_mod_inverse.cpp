// multiplicative modeulo inverse -- using extended euclid algo

#include<bits/stdc++.h>
using namespace std;

// extended gives us gcd and gcd in form of "ax+by"

class Triplet{
    public:
        int gcd;
        int x;
        int y;
};

Triplet extendedEuclid(int a,int b){
    //only runs 1 time
    if(a<b){
        return extendedEuclid(b,a);
    }
    // base case
    if(b==0){
        Triplet myAns;
        myAns.x=1;
        myAns.y=0;
        myAns.gcd=a;
        return myAns;
    }
    // Xeuclid steps
    Triplet nextAns=extendedEuclid(b,a%b); //this will give us x1 & y1
    // x=y1
    // y=x1-floor(a/b)*y1
    Triplet myAns;
    myAns.x=nextAns.y;
    myAns.y=nextAns.x-(floor(a/b)*(nextAns.y));
    myAns.gcd=nextAns.gcd;
    return myAns;
}

int main(){
    // b is the multi mod inv of given a
    // step 1 -> provide a & m for which u want b
    // step 2 -> find gcd of a and m
    // step 3 -> resulting b in ax+by will be the multi mod inverse
    int a=5,mod=12;
    Triplet tri=extendedEuclid(a,mod);
    cout<<"MultiModuloInverse : "<<tri.y;

}