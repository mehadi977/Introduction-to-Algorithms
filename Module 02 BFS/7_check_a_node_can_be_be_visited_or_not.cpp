#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000];
bool vis[1000];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int pre = q.front();
        q.pop();
        cout << pre << " ";
        for (int child : adj_list[pre])
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
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int src, dst;
    cin >> src >> dst;
    bfs(src);
    cout << endl;
    if (vis[dst])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}