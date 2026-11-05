#include <bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    // if (n == 0)
    //     return 0;
    // if (n == 1)
    //     return 1;
    if (n == 0 || n == 1)
        return n;
    int f1 = fibo(n - 1);
    int f2 = fibo(n - 2);
    return f1 + f2;
}
int fibo2(int n)
{
    if (n < 2)
        return n;
    return fibo2(n - 1) + fibo2(n - 2);
}
int main()
{

    cout << fibo2(10);

    return 0;
}