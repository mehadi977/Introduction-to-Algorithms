#include <bits/stdc++.h>
using namespace std;
vector<int> adj_lst[1000];
bool vis[1000];
int level[1000];
int prent[1000];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    // prent[src]=-1;  //alrady -1
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
                level[child] = level[pre] + 1;
                prent[child] = pre;
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
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(prent, -1, sizeof(prent));

    bfs(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " prent-> " << prent[i] << endl;
    }

    return 0;
}