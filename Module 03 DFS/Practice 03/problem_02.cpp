#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(1000);
vector<bool> vis(1000, false);
void dfs(int src)
{
    // cout << src << " ";
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
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
            cnt++;
        }
        // cout << endl;
    }
cout<<cnt;
    return 0;
}