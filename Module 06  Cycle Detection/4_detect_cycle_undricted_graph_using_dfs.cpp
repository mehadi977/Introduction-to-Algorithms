#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(1000);
vector<bool> vis(1000, false);
vector<int> parent(1000, -1);
bool cycle = false;
void dfs(int src)
{
    // cout << src << " ";
    vis[src] = true;
    for (int child : adj_lst[src])
    {
        if (vis[child] == true && parent[src] != child)
            cycle = true;
        if (vis[child] == false)
        {
            // parent set korte hobe recursion call karar age
            parent[child] = src;
            dfs(child);
            // parent[child] = src;
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
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            dfs(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " Parent-> " << parent[i] << endl;
    }

    if (cycle)
        cout << "Cycle decteted";
    else
        cout << "No cycle";
    return 0;
}