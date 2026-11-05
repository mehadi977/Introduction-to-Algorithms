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
vector<edge> edg_lst;
int n, e;
long long dis[10000];
bool cycle = false;
void bellman_ford(int src)
{
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto eg : edg_lst)
        {
            int a = eg.a, b = eg.b, c = eg.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    for (auto eg : edg_lst)
    {
        int a = eg.a, b = eg.b, c = eg.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            cycle = true;
    }
}
int main()
{
    for (int i = 0; i < 10000; i++)
        dis[i] = LLONG_MAX;

    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg_lst.push_back(edge(a, b, c));
    }
    // for (auto x : edg_lst)
    //     cout << x.a << " " << x.b << " " << x.c << endl;
    int src, t;
    cin >> src >> t;
    bellman_ford(src);
    if (cycle)
        cout << "Negative Cycle Detected\n";
    else
        while (t--)
        {
            int d;
            cin >> d;

            if (dis[d] == LLONG_MAX)
                cout << "Not Possible\n";
            else
                cout << dis[d] << endl;
        }

    return 0;
}