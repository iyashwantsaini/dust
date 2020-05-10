// ax+by=d
// we have to find no of pairs (x,y) which satisfy above equation

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// extended gives us gcd and gcd in form of "ax+by"

class Triplet{
    public:
        ll gcd;
        ll x;
        ll y;
};

Triplet extendedEuclid(ll a,ll b){
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

ll multimodinv(ll a,ll m){
    // b is the multi mod inv of given a
    // step 1 -> provide a & m for which u want b
    // step 2 -> find gcd of a and m
    // step 3 -> resulting b in ax+by will be the multi mod inverse
    ll y=extendedEuclid(a,m).y;
    return (y%m+m)%m;
}

int main(){
    ll a,b,d,g;
    // cin>>a>>b>>d;
    // a=4,b=10,d=6;
    // a=2,b=3,d=7;
    // a=6,b=14,d=0;
    a=2,b=3,d=6;

    g=__gcd(a,b);
    
    //d must be multiple of gcd(a,b)
    if(d%g){
        cout<<0<<endl;
        return 0;
    }
    // d must not be 0
    if(d==0){
        cout<<1<<endl;
        return 0;
    }
    
    // simplify both sides by dividing with g
    a/=g;
    b/=g;
    d/=g;

    // find smallest value for which (d-b*y)%a==0
    ll y1=((d%a)*multimodinv(b,a))%a;

    // to be used in calculating n
    ll firstval=d/b;

    if(d<y1*b){
        cout<<0<<endl;
        return 0;
    }

    // n=((d/b)-y1)/a
    ll n=(firstval-y1)/a;
    ll answer=n+1;
    cout<<answer<<endl;

}