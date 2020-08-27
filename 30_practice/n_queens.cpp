#include<bits/stdc++.h>
using namespace std;

// n*n chessboard
// place n queens

int board[11][11];

void nQueenHelper(int n,int row){
    if(row==n){
        // sol reache d
        // print mat
        // return
    }
    // place at all possible positions
    // move to smaller problem

}

void placeQueens(int n){
    memset(board,0,11*11*sizeof(int));
    int n=0;
    nQueenHelper(n,0);
}

int main(){
    placeQueens(4);
    return 0;
}