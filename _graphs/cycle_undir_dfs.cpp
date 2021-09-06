#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cycledfs(int n, vector<vector<int>> &adj, unordered_map<int, bool> &vis, int start, int par)
{
    vis[start] = 1; //global visited

    for (int i = 0; i < adj[start].size(); i++)
    {
        if (adj[start][i] == par)
        {
            continue;
        }
        if (vis[adj[start][i]] == 1)
        {
            return true;
        }
        if (cycledfs(n, adj, vis, adj[start][i], start))
        {
            return true;
        }
        vis[adj[start][i]] = 0;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*GRAPH==
    
    1--2    3--5--6---7
       |       |      |
       4       10--9--8--11

    */

    int N = 11; //total nodes
    vector<vector<int>> adj;
    adj.push_back({0}); //dont use

    adj.push_back({2});        //1
    adj.push_back({1, 4});     //2
    adj.push_back({5});        //3
    adj.push_back({2});        //4
    adj.push_back({3, 6, 10}); //5
    adj.push_back({5, 7});     //6
    adj.push_back({6, 8});     //7
    adj.push_back({7, 9, 11}); //8
    adj.push_back({8, 10});    //9
    adj.push_back({5, 9});     //10
    adj.push_back({8});        //11

    unordered_map<int, bool> vis;

    for (int i = 1; i < N; i++)
    {
        if (!vis[i])
        {
            if (cycledfs(N, adj, vis, i, -1))
            {
                cout << "Cycle Detected!";
                return 0;
            }
        }
    }

    cout << "No Cycle!";

    return 0;
}