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

vll fact(5 * 1e5 + 10);
vll inv_fact(5 * 1e5 + 10);
const int mod = 1e9 + 7;

ll modpow(ll b, ll e)
{
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1)
            ans = ans * b % mod;
    return ans;
}

void pre_fact()
{
    fact[0] = 1;
    inv_fact[0] = 1;
    for (int i = 1; i < 1e5 + 10; i++)
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
    ll n;
    cin >> n;
    vll v(n);
    set<ll> done;
    done.insert(-1);
    done.insert(n);
    priority_queue<pair<ll, ll>> pq;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        pq.push({v[i], i});
    }

    ll ans = 1;
    while (!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        auto it1 = done.upper_bound(e.second);
        auto it2 = --done.lower_bound(e.second);
        ll sz1 = (*it1 - e.second);
        ll sz2 = (e.second - *it2);
        if (sz1 * sz2 != v[e.second])
        {
            cout << 0 << '\n';
            return;
        }
        done.insert(e.second);

        ans = (ans * nCr(sz1 - 1 + sz2 - 1, sz1 - 1)) % mod;
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    pre_fact();

    int t;
    cin >> t;
    while (t--)
        solve();
}