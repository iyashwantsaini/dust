#include<bits/stdc++.h>
using namespace std;

//concentrate on selecting minimum and make a tree

int I =INT_MAX; //infinity --set it to max int
int edges[3][9]={
    {1, 1, 2, 2, 3, 4, 4, 5, 5},
    {2, 6, 3, 7, 4, 5, 7, 6, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};
int myset[8]={-1,-1,-1,-1,-1,-1,-1,-1}; //used to detect cycles
int included[9]={0}; //to avoid repetition
int t[2][6]; //to store solution

//to join parents
void unionfn(int u,int v){
    if(myset[u]<myset[v]){
        myset[u]=myset[u]+myset[v];
        myset[v]=u;
    }else{
        myset[v]=myset[u]+myset[v];
        myset[u]=v;
    }
}

//to find parents //collapsing find
int findfn(int u){
    int x=u;
    int v=0;
    while(myset[x]>0){
        x=myset[x];
    }
    //collapsing part
    while(u!=x){
        v=myset[u];
        myset[u]=x;
        u=v;
    }
    return x;
}

int main(){
    //in kruskal every step is recursive

    int n=7; //no of vertices
    int e=9; //no of edges
    int i,j,k,u,v;
    i=j=k=0;
    int min=I;

    while(i<n-1){
        min=I;
        //find min
        for(j=0;j<e;j++){ //searching in array edges
            if(included[j]==0&&edges[2][j]<min){
                min=edges[2][j];
                k=j; //saving minimum edge in k
                // u&v are vertices
                u=edges[0][j];
                v=edges[1][j];
            }
        }

        //check cycle :  then include in solution if no cycle
        if(findfn(u)!=findfn(v)){ //i.e if parents are not same
            t[0][i]=u;
            t[1][i]=v;
            //joining parents
            unionfn(findfn(u),findfn(v)); //making 1 as parent of other // joining
            i++;
        }
        included[k]=1; 
    }

    // print t
    int m=0;
    for(m=0;m<n-1;m++){
        cout<<"("<<t[0][m]<<")->"<<"("<<t[1][m]<<")"<<endl;
    }

}