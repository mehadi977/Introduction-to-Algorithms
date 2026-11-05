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
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg_lst.push_back(edge(a, b, c));
        // edg_lst.push_back(edge(b, a, c));
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    bellman_ford(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}