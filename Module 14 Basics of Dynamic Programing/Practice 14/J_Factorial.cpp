// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/J

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll rec(ll n)
{
    if (n == 0)
        return 1;
    ll a = rec(n - 1) * n;
    return a;
}
int main()
{
    ll n;
    cin >> n;
    ll ans = rec(n);
    cout << ans << endl;
    return 0;
}

// test case:
// 1:

// ou:

// 2:

// ou:
