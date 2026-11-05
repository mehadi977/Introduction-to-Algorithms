#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int a, b, c;
    edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
vector<edge> edg_lst;
int dis[1000];

void bellman_ford(int src)
{
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto eg : edg_lst)
        {
            int a = eg.a, b = eg.b, c = eg.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    bool cycle = false;
    for (auto eg : edg_lst)
    {
        int a = eg.a, b = eg.b, c = eg.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            cycle = true;
    }
    if (cycle)
        cout << "Negetive Cycle Detected" << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " << dis[i] << endl;
        }
    }
    // cout << "NO cycle" << endl;
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg_lst.push_back(edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    bellman_ford(0);

    return 0;
}
// no cycle
// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3

// cycle
// 4 4
// 0 1 5
// 1 2 3
// 2 3 2
// 3 1 -6