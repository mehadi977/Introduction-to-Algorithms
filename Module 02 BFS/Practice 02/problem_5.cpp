#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(1000);
vector<bool> vis(1000, false);
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
    bfs(0);
    int node;
    cin >> node;
    cout << adj_lst[node].size();
    return 0;
}