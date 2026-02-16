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

bool prob(int i, int j)
{
    if (i == j)
    {
        return true;
    }

    if (i > j)
    {
        swap(i, j);
    }

    if (i == 1 && j == 6)
    {
        return true;
    }
    if (i == 2 && j == 5)
    {
        return true;
    }
    if (i == 3 && j == 4)
    {
        return true;
    }

    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    if (n == 2)
    {
        if (prob(v[0], v[1]))
        {
            cout << 1 << '\n';
            return;
        }
        else
        {
            cout << 0 << '\n';
            return;
        }
    }
    vll pr;
    for (ll i = 0; i < n - 1; i++)
    {
        if (prob(v[i], v[i + 1]))
        {
            pr.push_back(i);
        }
    }

    ll ans = 0;
    // cerr << pr << '\n';
    if (pr.size() == 0)
    {
        cout << 0 << '\n';
        return;
    }
    ll left = pr[0];
    ll ct = 1;
    for (ll i = 1; i < pr.size(); i++)
    {
        if (pr[i] - left == 1)
        {
            ct++;
            left = pr[i];
        }
        else
        {
            ans += (ct + 1) / 2;
            ct = 1;
            left = pr[i];
        }
    }
    ans += (ct + 1) / 2;
    cout << ans << '\n';
    return;
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