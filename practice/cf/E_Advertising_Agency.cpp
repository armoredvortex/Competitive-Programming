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

const ll LIM = 1e4;
const ll mod = 1e9 + 7;
vector<ll> fact, inv_fact;

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
        b /= 2;
    }
    return res;
}

void precompute()
{
    fact.resize(LIM);
    inv_fact.resize(LIM);
    fact[0] = 1;
    inv_fact[0] = 1;
    for (ll i = 1; i < LIM; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv_fact[i] = modpow(fact[i], mod - 2);
    }
}

ll nCr(ll n, ll r)
{
    return (((fact[n] * inv_fact[r]) % mod) * inv_fact[n - r]) % mod;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll v(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(), v.end());
    ll mn = v.back();
    for (ll i = 0; i < k; i++)
    {
        mn = min(v[n - i - 1], mn);
    }
    ll ct = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] > mn)
            ct++;
    }
    cout << nCr(mp[mn], k - ct) << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    precompute();

    int t;
    cin >> t;
    while (t--)
        solve();
}