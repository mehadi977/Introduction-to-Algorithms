#include <bits/stdc++.h>
using namespace std;
int fac(int n)
{
    if (n == 1)
        return 1;
    // int f = fac(n - 1);
    // return n * f;
    return n * fac(n - 1);
}
int main()
{
    cout << fac(5);
    return 0;
}