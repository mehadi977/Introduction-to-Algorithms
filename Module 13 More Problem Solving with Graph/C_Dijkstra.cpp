// Problem Link:
// https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<pair<ll, ll>>> adj_lst(100005);
vector<ll> dis(100005);
vector<ll> parnt(100005);
void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dis[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();
        ll par_node = par.second;
        ll par_dis = par.first;

        for (auto child : adj_lst[par_node])
        {
            ll child_node = child.first;
            ll child_dis = child.second;
            if (child_dis + par_dis < dis[child_node])
            {
                dis[child_node] = child_dis + par_dis;
                pq.push({dis[child_node], child_node});
                parnt[child_node] = par_node;
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 100005; i++)
    {
        dis[i]=LLONG_MAX;
        parnt[i]=-1;
    }
    
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_lst[a].push_back({b, c});
        adj_lst[b].push_back({a, c});
    }

    dijkstra(1);
    // for (ll i = 1; i <= n; i++)
    // {
    //     // cout << i << " " << dis[i] << endl;
    //     cout << i << " " << parnt[i] << endl;
    // }
    if (dis[n] == LLONG_MAX)
        cout << -1 << endl;
    else
    {
        ll node = n;
        vector<ll> v;
        while (node != -1)
        {
            v.push_back(node);
            node = parnt[node];
        }
        reverse(v.begin(), v.end());
        for (ll a : v)
            cout << a << " ";
    }
    return 0;
}

// test case:
// 1:
//   5 6
//  1 2 2
//  2 5 5
//  2 3 4
//  1 4 1
//  4 3 3
//  3 5 1

// 1 4 3 5

// 2:
//  5 6
//  1 2 2
//  2 5 5
//  2 3 4
//  1 4 1
//  4 3 3
//  3 5 1

// 1 4 3 5