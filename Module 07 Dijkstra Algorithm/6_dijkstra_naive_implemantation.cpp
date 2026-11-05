#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj(1000);
// vector<bool> vis(1000, false);
vector<int> dis(1000, INT_MAX);
void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    // vis[src] = true;
    dis[src] = 0;
    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        int par_node = par.first;
        int par_dis = par.second;

        // cout << par.first << " ";
        for (auto child : adj[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            // path relaxation
            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                q.push({child.first, par_dis + child_dis});
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
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << dis[i] << endl;
    // }

    return 0;
}