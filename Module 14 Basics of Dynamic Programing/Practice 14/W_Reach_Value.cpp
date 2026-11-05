// Problem Link:

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool rec(ll i, ll n)
{
    if (i == n)
        return true;
    if (i > n)
        return false;
    bool a = rec(i * 20, n);
    bool b = rec(i * 10, n);
    return a || b;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        bool ans = rec(1, n);
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

// test case:
// 1:

// ou:

// 2:

// ou:
