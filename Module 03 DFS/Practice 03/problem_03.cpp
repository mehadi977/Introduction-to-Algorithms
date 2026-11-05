#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(1000);
vector<bool> vis(1000);
// vector<vector<int>>cmp;
int sz = 0;
vector<int> ans;
void dfs(int src)
{
    // cout << src << " ";
    sz++;
    vis[src] = true;
    for (int child : adj_lst[src])
        if (vis[child] == false)
            dfs(child);
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
    // dfs(0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
            ans.push_back(sz);
            sz = 0;
        }
    }
    sort(ans.begin(), ans.end());
    for (int x : ans)
        cout << x << " ";
    return 0;
}