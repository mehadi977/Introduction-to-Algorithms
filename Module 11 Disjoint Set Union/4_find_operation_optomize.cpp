#include <bits/stdc++.h>
using namespace std;
int par[1000];
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leder = dsu_find(par[node]);
    par[node]=leder;
    return leder;
}
int main()
{

    memset(par, -1, sizeof(par));
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;
    cout << dsu_find(4) << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << i << " -> " << par[i] << endl;
    }

    return 0;
}