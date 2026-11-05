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
int dis[1000];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<edge> edg_lst;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg_lst.push_back(edge(a, b, c));
    }
    // for (auto eg : edg_lst)
    // {
    //     cout << eg.a << " " << eg.b << " " << eg.c << endl;
    // }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

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

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}