#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    else if (n == 2)
    {
        cout << -1 << '\n';
        return;
    }
    else if (n == 3)
    {
        cout << -1 << '\n';
        return;
    }
    else if (n == 4)
    {
        cout << "2 4 1 3\n";
        return;
    }

    if (n % 5 == 0)
    {
        ll ct = 1;

        while (ct != n - 1)
        {
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            if (ct != n - 1)
            {
                ct += 2;
            }
        }
        cout << '\n';
    }
    else if (n % 5 == 1)
    {
        ll ct = 1;
        while (ct != n)
        {
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
        }
        cout << ct << ' ';

        cout << '\n';
    }
    else if (n % 5 == 2)
    {
        ll ct = 1;
        while (ct != (n / 5 - 1) * 5 + 1)
        {
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
        }
        while (ct != n - 1)
        {
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 5;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
        }
        cout << '\n';
    }
    else if (n % 5 == 3)
    {
        ll ct = 1;
        while (ct != (n / 5 - 1) * 5 + 1)
        {
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
        }
        while (ct != n)
        {
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 5;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
        }
        cout << '\n';
    }
    else
    {
        ll ct = 1;
        while (ct != max(n / 5, 0ll) * 5 + 1)
        {
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct -= 3;
            cout << ct << ' ';
            ct += 2;
            cout << ct << ' ';
            ct += 2;
        }
        ct += 1;
        cout << ct << ' ';
        ct += 2;
        cout << ct << ' ';
        ct -= 3;
        cout << ct << ' ';
        ct += 2;
        cout << ct << ' ';

        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--)
        solve();
}