#include<bits/stdc++.h>
using namespace std;
#include "queueCpp.h"

void BFS(int a[][8],int i){ //i=staring number
    int visitedBFS[8]={0};
    Queue q;
    int u=0;

    cout<<i<<" ";
    visitedBFS[i]=1;
    q.Enqueue(i);

    while(!q.isEmpty()){
        u=q.Dequeue();
        for(int v=1;v<=7;v++){
            if(a[u][v]==1&&visitedBFS[v]==0){ //i.e it hasn't been visited yet and is adjacent to current node
                cout<<v<<" ";
                visitedBFS[v]=1;
                q.Enqueue(v);
            }
        }
    }
}

void DFS(int a[][8],int i){ //i=starting number
    static int visitedDFS[8]={0}; //static because this fn is recursive
    if(visitedDFS[i]==0){ //i.e hasn't been visited
        cout<<i<<" ";
        visitedDFS[i]=1;

        for(int v=1;v<=7;v++){
            if(a[i][v]==1&&visitedDFS[v]==0){
                DFS(a,v);
            }
        }
    }

}

int main(){
    int A[][8]={  //we won't use 0 index here
        {0,     0,0,0,0,0,0,0},

        {0,     0,1,1,1,0,0,0},
        {0,     1,0,1,0,0,0,0},
        {0,     1,1,0,1,1,0,0},
        {0,     1,0,1,0,1,0,0},
        {0,     0,0,1,1,0,1,1},
        {0,     0,0,0,0,1,0,0},
        {0,     0,0,0,0,1,0,0}
    };

    // cout<<"BFS : start : 1"<<endl;
    // BFS(A,1);cout<<"\n";
    // cout<<"DFS : start : 1"<<endl;
    // DFS(A,1);cout<<"\n";
    cout<<"BFS : start : 5"<<endl;
    BFS(A,5);cout<<"\n";
    cout<<"DFS : start : 5"<<endl;
    DFS(A,5);cout<<"\n";

    //   GRAPH  no. of vertices ==7
    //   1--2
    //   |\ | 
    //   | \|
    //   4--3
    //    \/
    //    5
    //    /\
    //   6 7
}