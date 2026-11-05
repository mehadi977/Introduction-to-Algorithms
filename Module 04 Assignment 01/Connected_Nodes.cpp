#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_lst(10000);
vector<bool> vis(10000, false);

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_lst[a].push_back(b);
        adj_lst[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        vector<int> ans;
        int x;
        cin >> x;
        if (adj_lst[x].size() == 0)
            ans.push_back(-1);
        else
        {
            for (int c : adj_lst[x])
                // cout << c << " ";
                ans.push_back(c);
        }
        sort(ans.begin(), ans.end(), greater<int>());
        for (int z : ans)
            cout << z << " ";
        cout << endl;
    }

    return 0;
}