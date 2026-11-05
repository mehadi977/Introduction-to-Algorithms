#include <bits/stdc++.h>
using namespace std;
int par[100002];
int group_size[100002];
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (group_size[leader1] > group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{
    // memset(par, -1, sizeof(par));
    // memset(group_size, 1, sizeof(group_size));
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA != leaderB)
            dsu_union(a, b);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " - " << par[i] << endl;
    // }
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        int leader1 = dsu_find(1);
        int leader = dsu_find(i);
        if (leader1 != leader)
        {
            cnt++;
            v.push_back(i);
            dsu_union(1, i);
        }
    }
    cout << cnt << endl;
    for (int val : v)
    {
        cout << 1 << " " << val << endl;
    }

    return 0;
}