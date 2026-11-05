#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_list(100005);
bool vis[100005];
int prant[100005];
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
        for (auto child : adj_list[pre])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                prant[child] = pre;
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
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(prant, -1, sizeof(prant));

    int src = 1, dst = n;
    bfs(src);
    int node = dst;
    vector<int> path;
    if (vis[dst] == false)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    while (node != -1)
    {
        path.push_back(node);
        node = prant[node];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int x : path)
        cout << x << " ";

    return 0;
}