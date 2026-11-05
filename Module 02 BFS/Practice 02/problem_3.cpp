// Question: You will be given an undirected graph as input. Then you will be given a query Q. For each query, you will be given source S and destination D. You need to print the shortest distance between S and D. If there is no path from S to D, print -1.

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(1000);
bool vis[1000];
int prant[1000];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int pre = q.front();
        q.pop();
        // cout << pre << " ";
        for (int child : adj_lst[pre])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                prant[child] = pre;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_lst[a].push_back(b);
        adj_lst[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;
        int node = dst;
        memset(vis, false, sizeof(vis));
        memset(prant, -1, sizeof(prant));
        bfs(src);
        vector<int> path;

        while (node != -1)
        {
            path.push_back(node);
            node = prant[node];
        }
        if (vis[dst] == false)
            cout << -1 << endl;
        else
            cout << path.size() - 1 << endl;
    }

    return 0;
}