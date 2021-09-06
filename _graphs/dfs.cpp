#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<int>> &adj, unordered_map<int, int> &vis, int start)
{
    //mark visited
    vis[start] = 1;
    cout << start << " ";

    for (int i = 0; i < adj[start].size(); i++)
    {
        if (vis[adj[start][i]] == 0)
        {
            dfs(adj, vis, adj[start][i]);
        }
    }

    cout<<"\nreturning from "<<start<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //graph ==
    //   1--2
    //   |\ |
    //   | \|
    //   4--3
    //    \/
    //    5
    //    /\
    //   6 7

    vector<vector<int>> adj;     //adjacency matrix
    adj.push_back({0, 0, 0});    //0 dont use
    adj.push_back({2, 3, 4});    //1
    adj.push_back({1, 3});       //2
    adj.push_back({1, 2, 4, 5}); //3
    adj.push_back({1, 3, 5});    //4
    adj.push_back({3, 4, 6, 7}); //5
    adj.push_back({5});          //6
    adj.push_back({5});          //7

    unordered_map<int, int> vis; //visited map

    //DFS

    dfs(adj, vis, 1);

    return 0;
}