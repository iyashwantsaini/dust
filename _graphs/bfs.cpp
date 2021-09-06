#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    //BFS

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int curr = q.front();
            q.pop();
            vis[curr] = 1;

            cout << curr << " ";

            for (int i = 0; i < adj[curr].size(); i++)
            {
                if (vis[adj[curr][i]] == 0)
                {
                    q.push(adj[curr][i]);
                    vis[adj[curr][i]] = 1;
                }
            }

            cout<<"\nreturning from "<<curr<<"\n";
        }
    }

    return 0;
}