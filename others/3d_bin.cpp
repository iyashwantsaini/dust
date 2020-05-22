#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z, n;
    cin >> x >> y >> z >> n;
    int a[x*y*z];
    for (int i = 0; i < x*y*z; i++){
        cin>>a[i];
    }
    int countbin=0;
    int r1dmin,r1dmax;
    int r2dmin,r2dmax;
    int indexi=0,indexj=0,indexk=0;

    for(int i=0;i<x*y*z;i+=y*z){
        if(n>=a[i]){
            r1dmin=a[i];
            indexi=i/x;
            r1dmax=a[i+y*z-1];
        }
    }
    cout<<r1dmin<<" "<<r1dmax<<endl;
    for(int i=0;i<x*y*z;i+=z){
        if(n>=a[i]){
            r2dmin=a[i];
            indexj=i;
            r2dmax=a[i+z-1];
        }
    }
    cout<<r2dmin<<" "<<r2dmax<<endl;

    int first=0;
    int last=x*y*z-1;
    int middle=(first+last)/2;

    while (first <= last) {
        if (a[middle] < n)
            first = middle + 1; 
        else if (a[middle] == n) {
            break;
        }
        else{
            last=middle-1;
        }
        middle = (first + last)/2;
        countbin++;
    }
    
    while(indexj>x){
        indexj-=x;
    }
    while(indexj>y){
        indexj-=y;
    }
    cout<<indexi<<" "<<indexj<<endl;

    if (first > last){
        cout<<"0"<<endl;
    }
    cout<<countbin<<endl;

}