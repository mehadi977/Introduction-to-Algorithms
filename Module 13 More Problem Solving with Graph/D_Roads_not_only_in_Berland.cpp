// Problem Link: https://codeforces.com/problemset/problem/25/D

#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];
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
    for (int i = 1; i <= 1005; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    int n, e;
    cin >> n;
    e = n - 1;
    vector<pair<int, int>> rmv;
    vector<pair<int, int>> add;
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
        {
            rmv.push_back({a, b});
        }
        else
            dsu_union(b, a);
    }
    for (int i = 2; i <= n; i++)
    {
        int leader1 = dsu_find(1);
        int leader2 = dsu_find(i);
        if (leader1 != leader2)
        {
            dsu_union(i,1);
            add.push_back({i, 1});
        }
    }
    cout << rmv.size() << endl;
    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << add[i].first << " " << add[i].second << " "<<endl;
    }

    return 0;
}