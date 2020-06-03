#include<bits/stdc++.h>
using namespace std;
// nxn chessboard -- nqueens place

int board[11][11];

bool ispossible(int n,int row, int col){
    // we just have to check up, upperdiagright, upperdiagleft 
    // check col
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    // upperleftdiag
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    // upperright diag
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}

void nqueenhelper(int n,int row){
    if(row==n){
        // we have reached soln
        // print board
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        // return
        return;
    }
    // place at all possible positions ans move to smaller prob
    for(int j=0;j<n;j++){
        if(ispossible(n,row,j)){
            // before call
            board[row][j]=1;
            nqueenhelper(n,row+1);
            // after call make 0 for backtrack
            board[row][j]=0;
        }
    }
    return;
}

void placequeens(int n){
    memset(board,0,11*11*sizeof(int));
    nqueenhelper(n,0);
}

int main(){

    placequeens(4);
}    