#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cyclebfs(int n, vector<vector<int>> &adj, unordered_map<int, bool> &vis, int start)
{
    queue<pair<int, int>> q; //curr,parent
    q.push({start, -1});
    vis[start] = 1;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {

            int curr = q.front().first;
            int par = q.front().second;
            q.pop();

            for (int i = 0; i < adj[curr].size(); i++)
            {
                //if its a parent
                if (adj[curr][i] == par)
                {
                    continue;
                }
                //if already visited -> cycle
                if (vis[adj[curr][i]] == 1)
                {
                    return true;
                }
                //no cycle yet -> add to queue
                q.push({adj[curr][i], curr});
                vis[curr] = 1;
            }
        }
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
            if (cyclebfs(N, adj, vis, i))
            {
                cout << "Cycle Detected!";
                return 0;
            }
        }
    }

    cout << "No Cycle!";

    return 0;
}