#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// sample input
// 3
// 4 3 2
// 1 8 3
// 1 1 8

// here repetitoins are there
// int min_cost(int **a,int si,int sj,int ei,int ej){
//     // reached end
//     if(si==ei&&sj==ej){
//         return a[ei][ej];
//     }
//     // if we reached out of matrix
//     if(si>ei||sj>ej){
//         // return max so that this path will not be taken
//         return INT_MAX;
//     }
//     // as only 3 directions are allowed
//     int dir1=min_cost(a,si+1,sj,ei,ej); //down
//     int dir2=min_cost(a,si,sj+1,ei,ej); //right
//     int dir3=min_cost(a,si+1,sj+1,ei,ej); //diagonally
//     return a[si][sj]+min(dir1,min(dir2,dir3));
// }

// dynamic
int min_cost(int **a,int si,int sj,int ei,int ej,int **storage){
    // reached end
    if(si==ei&&sj==ej){
        return a[ei][ej];
    }
    // if we reached out of matrix
    if(si>ei||sj>ej){
        // return max so that this path will not be taken
        return INT_MAX;
    }
    if(storage[si][sj]>-1){
        return a[si][sj]+storage[si][sj];
    }
    // as only 3 directions are allowed
    int dir1=min_cost(a,si+1,sj,ei,ej,storage); //down
    int dir2=min_cost(a,si,sj+1,ei,ej,storage); //right
    int dir3=min_cost(a,si+1,sj+1,ei,ej,storage); //diagonally
    storage[si][sj]=min(dir1,min(dir2,dir3));
    return a[si][sj]+min(dir1,min(dir2,dir3));
}


int main(){
    // we are calculating from square
    // just take rows and cols if we need rectangle
    int dim;
    cin>>dim;
    int **a=new int*[dim];
    for(int i=0;i<dim;i++){
        a[i]=new int[dim];
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cin>>a[i][j];
        }
    }
    // we have to reach from (0,0) to (dim-1,dim-1)
    // cout<<min_cost(a,0,0,dim-1,dim-1)<<endl; 

    // dynamic
    int **storage=new int*[dim];
    for(int i=0;i<dim;i++){
        storage[i]=new int[dim];
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            storage[i][j]=-1;
        }
    }

    cout<<min_cost(a,0,0,dim-1,dim-1,storage)<<endl; 

    // delete arrays
    for(int i=0;i<dim;i++){
        delete [] storage[i];
    }
    delete storage;
    for(int i=0;i<dim;i++){
        delete [] a[i];
    }
    delete a;
}