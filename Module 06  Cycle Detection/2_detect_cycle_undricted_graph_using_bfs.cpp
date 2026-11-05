#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(1000);
vector<bool> vis(1000, false);
vector<int> parent(1000, -1);
bool cycle = false;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << " ";
        for (int child : adj_lst[par])
        {
            if (vis[child] == true && parent[par]!=child)
                cycle = true;
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
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
    // bfs(0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            bfs(i);
    }
    if (cycle)
        cout << "Cycle Dicteted";
    else
        cout << "No Cycle";

    return 0;
}