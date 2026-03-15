#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if (n == 2)
    {
        cout << 3 << '\n';
        return;
    }
    if (n == 3 || n == 4)
    {
        cout << 4 << '\n';
        return;
    }

    cout << 5 << '\n';
    return;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}