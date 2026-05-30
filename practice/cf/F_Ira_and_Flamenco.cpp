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

const ll mod = 1e9 + 7;

ll mod_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    return ans;
}

ll mod_inv(ll x)
{
    return mod_pow(x, mod - 2);
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    map<ll, ll> mp;
    vll v;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (!mp[a])
        {
            v.push_back(a);
        }
        mp[a]++;
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    ll mult = 1;
    ll it;
    for (it = 0; it < min((ll)v.size(), m - 1); it++)
    {
        mult = (mult * mp[v[it]]) % mod;
    }

    while (it < v.size())
    {
        mult = (mult * mp[v[it]]) % mod;
        if (v[it] - v[it - m + 1] < m)
        {
            ans = (ans + mult) % mod;
        }
        mult = (mult * mod_inv(mp[v[it - m + 1]])) % mod;
        it++;
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