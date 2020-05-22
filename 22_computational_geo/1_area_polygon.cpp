#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 4
// 1 1
// 1 5
// 5 5
// 5 1

// area=16

class point{
    public:
        double x,y;
};

class polygon{
    public:
        point* points;
        polygon(int nofpoints){
            points = new point[nofpoints]; 
        }
};

double area(polygon p,int n){
    // find area of triangles and add them
    double polyarea=0;
    // to find are find cross products of ith and i+1th vectors
    for(int i=0;i<n-1;i++){
        
        double x1=p.points[i].x-p.points[0].x;
        double y1=p.points[i].y-p.points[0].y;
        double x2=p.points[i+1].x-p.points[0].x;
        double y2=p.points[i+1].y-p.points[0].y;
        double cross=x1*y2-x2*y1;
        polyarea+=cross;
    }
    return abs(polyarea)/2;
}

int main(){

    int n;
    cout<<"Enter no of sides : ";
    cin>>n;
    polygon p(n);

    for(int i=0;i<n;i++){
        cin>>p.points[i].x;
        cin>>p.points[i].y;
    }
    // for(int i=0;i<n;i++){
    //     cout<<p.points[i].x <<" ";
    //     cout<<p.points[i].y<<" ";
    //     cout<<"\n";
    // }

    cout<<"Area : ";
    cout<<area(p,n);

}