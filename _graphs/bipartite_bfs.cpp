#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //GRAPH
    // ONE ->bipart
    // 1--2--3--4
    //    |     |
    //    7--6--5--8
    //

    // TWO ->notbipart
    // 1--2--3--4
    //    |     |
    //    6-----5--7

    vector<vector<int>> adj;
    adj.push_back({0}); //0 ->not used
    
    //ONE
    // adj.push_back({2}); //1
    // adj.push_back({1,3,7}); //2
    // adj.push_back({2,4}); //3
    // adj.push_back({3,5}); //4
    // adj.push_back({4,6,8}); //5
    // adj.push_back({5,7}); //6
    // adj.push_back({2,6}); //7
    // adj.push_back({5}); //8

    //TWO
    adj.push_back({2}); //1
    adj.push_back({1,3,6}); //2
    adj.push_back({2,4}); //3
    adj.push_back({3,5}); //4
    adj.push_back({4,6,7}); //5
    adj.push_back({2,5}); //6
    adj.push_back({5}); //7


    int *colors=new int [9]; //1->8 useful
    for(int i=0;i<9;i++){
        colors[i]=-1;
    }

    queue<int> q;
    q.push(1);
    colors[1]=0;

    while(!q.empty()){
        int size=q.size();
        while(size--){
            int curr=q.front();
            int color=colors[curr];
            q.pop();

            //see adjacent

            for(int i=0;i<adj[curr].size();i++){
                if(colors[adj[curr][i]]==color){
                    cout<<"NOT BIPARTITE!";
                    return 0;
                }
                if(colors[adj[curr][i]]==-1){
                    q.push(adj[curr][i]);
                    colors[adj[curr][i]]=color==0?1:0;
                }
            }

        }
    }

    cout<<"BIPRATITE!";

    return 0;
}