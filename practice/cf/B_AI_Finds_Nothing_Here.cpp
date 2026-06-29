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

const ll mod = 998244353;

ll modpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

void solve()
{
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    ll ways = modpow(2, r * c - 1);

    ll extendc = modpow(modpow(2, c - 1), n - r);
    ll extendr = modpow(modpow(2, r - 1), m - c);

    // cerr << ways << ' ' << extendc << ' ' << extendr << '\n';

    ll ans = (((extendc * extendr) % mod) * ways) % mod;
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