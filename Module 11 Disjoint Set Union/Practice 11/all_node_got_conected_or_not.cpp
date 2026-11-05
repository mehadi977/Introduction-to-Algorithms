#include <bits/stdc++.h>
using namespace std;
int par[100001];
int group_size[100001];
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int ledar = dsu_find(par[node]);
    return ledar;
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
    memset(group_size, 1, sizeof(group_size));
    memset(par, -1, sizeof(par));
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA != leaderB)
            dsu_union(a, b);
    }
    bool flag = true;
    int leader_n = dsu_find(n);
    for (int i = 1; i <= n; i++)
    {
        int lead_node = dsu_find(i);
        if (leader_n != lead_node)
            flag = false;
    }
    if (flag)
        cout << "connected\n";
    else
        cout << "Not conected\n";

    return 0;
}