#include <bits/stdc++.h>
using namespace std;
int par[1000];
int group_size[1000];
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (group_size[leader1] >= group_size[leader2])
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
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));
    dsu_union(1, 2);
    dsu_union(3, 2);
    dsu_union(4, 3);
    dsu_union(3, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << i << " -> " << par[i] << endl;
    }

    return 0;
}