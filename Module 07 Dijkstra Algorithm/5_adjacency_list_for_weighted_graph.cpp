#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj_lst(1000);
int main()
{

    int n, e;
    cin>>n>>e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_lst[a].push_back({b, c});
        adj_lst[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto p : adj_lst[i])
            cout << p.first << " " << p.second << ", ";
        cout << endl;
    }

    return 0;
}