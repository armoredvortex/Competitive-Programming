#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    a %= n;
    b %= m;

    if (gcd(n, a) != 1 || gcd(b, m) != 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}