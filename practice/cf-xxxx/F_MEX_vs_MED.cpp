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
    vll pos(n + 1);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        pos[v[i]] = i;
    }

    vll mn(n + 1), mx(n + 1);
    mn[0] = pos[0];
    mx[0] = pos[0];
    for (ll i = 1; i < n + 1; i++)
    {
        mn[i] = min(pos[i], mn[i - 1]);
        mx[i] = max(pos[i], mx[i - 1]);
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll left = mn[v[i]];
        ll right = mx[v[i]];

        // cerr << left << ' ' << right << "\n";
        ll dist = max(abs(right - i), abs(left - i));
        ll k1 = i - dist;
        ll k2 = i + dist;
        ans += max(0ll, min(k1 + 1, n - k2));
        // cerr << max(0ll, min(k1 + 1, n - k2)) << '\n';
    }

    for (ll i = 0; i < n; i++)
    {
        ll left = mn[v[i]];
        ll right = mx[v[i]];

        // cerr << left << ' ' << right << "\n";
        ll dright = abs(right - i);
        ll dleft = abs(left - i);

        ll k1, k2;
        if (dleft >= dright)
        {
            k1 = i - dleft;
            k2 = i + dleft + 1;
        }
        else
        {
            k1 = i - dright + 1;
            k2 = i + dright;
        }

        ans += max(0ll, min(k1 + 1, n - k2));
        // cerr << max(0ll, min(k1 + 1, n - k2)) << '\n';
    }

    cout << ans << "\n";
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