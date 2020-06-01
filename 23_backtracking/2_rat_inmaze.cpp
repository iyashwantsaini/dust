#include<bits/stdc++.h>
using namespace std;

// sample
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// o/p
// 1 0 0 
// 1 0 0 
// 1 1 1

void printsolution(int **solution,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void mazehelp(int **maze,int n,int** solution,int x,int y){
    
    if(x==n-1&&y==n-1){
        solution[x][y]=1;
        printsolution(solution,n);
        return;
    }

    if(x>=n||x<0||y>=n||y<0||maze[x][y]==0||solution[x][y]==1){
        return;
    }

    solution[x][y]=1;
    mazehelp(maze,n,solution,x-1,y); //up
    mazehelp(maze,n,solution,x+1,y); //down
    mazehelp(maze,n,solution,x,y-1); //left
    mazehelp(maze,n,solution,x,y+1); //right
    solution[x][y]=0;
}

void ratinmaze(int **maze,int n){
    int** solution =new int*[n];
    for(int i=0;i<n;i++){
        solution[i]=new int[n]();
    }
    // initial take position 1row1col
    mazehelp(maze,n,solution,0,0);
}

int main(){
    int n;
    cin>>n;
    int **maze=new int*[n];
    for(int i=0;i<n;i++){
        maze[i]=new int[n];
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<maze[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    ratinmaze(maze,n);

    return 0;
}