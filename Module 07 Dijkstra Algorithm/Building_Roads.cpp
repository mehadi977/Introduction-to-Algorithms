#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(100001);
vector<bool> vis(100001, false);
void dfs(int src)
{
    // cout << src << " ";
    vis[src] = true;

    for (int child : adj[src])
    {
        if (!vis[child])
            dfs(child);
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ans.push_back(i);
        }
    }
    int sz = ans.size();
    cout << sz - 1 << endl;
    for (int i = 0; i < sz-1; i++)
    {
        cout << ans[i] << " " << ans[i+1] << endl;
    }

    return 0;
}