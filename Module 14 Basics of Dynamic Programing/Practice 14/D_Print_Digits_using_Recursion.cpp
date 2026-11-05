// Problem Link:

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void rec(ll n)
{
    if (n < 1)
        return;
    rec(n / 10);
    cout << n % 10 << " ";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 0)
            cout << 0 << endl;
        else
        {
            rec(n);
            cout << endl;
        }
    }

    return 0;
}

// test case:
// 1:

// ou:

// 2:

// ou:

// //Problem Link:

// #include<bits/stdc++.h>
// using namespace std;
//  #define ll long long int
// int main()
// {
//         int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<ll> v;
//         while (true)
//         {
//             if (n < 1)
//                 break;
//             ll a = n % 10;
//             v.push_back(a);
//             n = n / 10;
//         }
//         reverse(v.begin(), v.end());
//         for (ll a : v)
//             cout << a << " ";
//         cout << endl;
//     }

//     return 0;
// }

// //test case:
// //1:

// //ou:

// //2:

// //ou:
