#include<bits/stdc++.h>
using namespace std;

//concentrate on making tree and always select min edge

int I =INT_MAX; //infinity --set it to max int
int cost[][8]={
    {I,I,I,I,I,I,I,I},

    {I,     I,25,I,I,I,5,I},
    {I,     25,I,12,I,I,I,10},
    {I,     I,12,I,8,I,I,I},
    {I,     I,I,8,I,16,I,14},
    {I,     I,I,I,16,I,20,18},
    {I,     5,I,I,I,20,I,I},
    {I,     I,10,I,14,18,I,I}
};
int near[8]={I,I,I,I,I,I,I,I};
int t[2][6];

int main(){
    int min=I;
    int n=7;
    int u,v; //vertices connecting an edge

    //STEP1
    //finding min
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){  //will check only upper triangular as j=i
            if(cost[i][j]<min){
                min=cost[i][j];
                u=i; //saves value 1
                v=j; //saves value 6
            }
        }
    }
    //saving edges to "t" and seeting 1 and 6 in "near" as 0
    t[0][0]=u;
    t[1][0]=v;
    near[u]=near[v]=0; //0 means used in MST already
    // updating all nodes whether they are near to 6 or 1 in "near" array
    for(int i=1;i<=n;i++){
        if(near[i]!=0){
            if(cost[i][u]<cost[i][v]){
                near[i]=u;
            }else{
                near[i]=v;
            }
        }
    }

    //STEP2 --REPEATING STEP
    int k=0;
    for(int i=1;i<n-1;i++){ //upto n-1 because last will not be connected to anyone
        min=I; //resetting min to infinity

        // finding next minimum from remaining
        for(int j=1;j<=n;j++){
            if(near[j]!=0&&cost[j][near[j]]<min){
                k=j; // k saves ndoe joining minimum node
                min=cost[j][near[j]];
            }
        }
        //saving min edge and making used nodes in "near" 0
        t[1][i]=k;
        t[0][i]=near[k];
        near[k]=0;
        //updating near
        for(int j=1;j<=n;j++){
            if(near[j]!=0&&cost[j][k]<cost[j][near[j]]){
                near[j]=k;
            }
        }
    }

    // print t
    
    // for(int i=0;i<n-1;i++)
    // {
    //     cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    // }
    int m=0;
    for(m=0;m<n-1;m++){
        cout<<"("<<t[0][m]<<")->";
    }
    m--;
    cout<<"("<<t[1][m]<<")"<<endl;

}

