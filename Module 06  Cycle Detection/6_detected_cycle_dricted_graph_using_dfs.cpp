#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(1000);
vector<bool> vis(1000, false);
vector<bool> path(1000, false);
bool cycle = false;
void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    path[src] = true;
    for (int child : adj_lst[src])
    {
        if (vis[child] == true && path[child] == true)
            cycle = true;
        if (vis[child] == false)
            dfs(child);
    }
    path[src] = false;
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
    }
    // dfs(0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            dfs(i);
    }
    if (cycle)
        cout << "Cycle detected";
    else
        cout << "No Cycle";
    return 0;
}