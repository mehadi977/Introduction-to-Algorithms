#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(1000);
vector<bool> vis(1000, false);
int cnt = 0;
void dfs(int src)
{
    // cout << src << " ";
    cnt++;
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
    int nod;
    cin >> nod;
    dfs(nod);
    cout << cnt;
    return 0;
}