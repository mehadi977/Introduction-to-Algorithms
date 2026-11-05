#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj(100);
vector<int> dis(100, INT_MAX);
void dijkstra(int src)
{
    // queue<pair<int, int>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int par_node = par.second;
        int par_dis = par.first;
        for (auto child : adj[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if (child_dis + par_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
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

    return 0;
}

// 5 8
// 1 0 10
// 1 2 1
// 0 2 7
// 0 3 4 
// 2 3 1
// 3 4 5
// 1 4 3
// 2 4 5

// 0 -> 0
// 1 -> 6
// 2 -> 5
// 3 -> 4
// 4 -> 9