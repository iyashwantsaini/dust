#include<bits/stdc++.h>
using namespace std;

// convex hull gives minimum boundary including all points

class point{
    public:
        int x,y;
};

bool tochange(point p,point q,point r){
    int x1=q.x-p.x;
    int y1=q.y-p.y;
    int x2=r.x-q.x;
    int y2=r.y-q.y;

    int val=x1*y2-x2*y1;
    return val>0; 
}

void convexhull(point points[],int n){
    vector<point> hull;

    int leftmost=0;
    // to get leftmost point
    for(int i=1;i<n;i++){
        if(points[i].x<points[leftmost].x){
            leftmost=i;
        }
    }

    int p=leftmost;
    do{
        hull.push_back(points[p]);
        int q=(p+1)%n;

        for(int i=0;i<n;i++){
            if(tochange(points[p],points[q],points[i])){
                q=i;
            }
        }
        p=q;
    }while(p!=leftmost);

    for(int i=0;i<hull.size();i++){
        cout<<hull.at(i).x<<" "<<hull.at(i).y<<endl;
    }

}

int main(){
    point p[]={{0,4},{1,1},{2,2},{4,0},{4,4},{0,0},{3,3}};
    convexhull(p,7);
    return 0;
}