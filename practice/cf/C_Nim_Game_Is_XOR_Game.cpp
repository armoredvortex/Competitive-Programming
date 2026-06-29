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
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll x = 0;
    for (ll i = 0; i < n; i++)
    {
        x ^= v[i];
    }

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    ll ans = 0;
    if (x == 0)
    {
        ans++;
    }
    for (ll i = 0; i < n; i++)
    {
        if ((x ^ v[i]) < v[i])
        {
            ans++;
        }
    }
    cout << ans << '\n';
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