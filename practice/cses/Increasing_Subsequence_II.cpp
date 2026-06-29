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

void update(vector<ll> &fen, ll old, ll nw, ll i)
{
    while (i < fen.size())
    {
        fen[i] = (fen[i] + nw - old) % mod;
        i += (-i & i);
    }
}

ll query(vector<ll> &fen, ll i)
{
    ll res = 0;
    while (i)
    {
        res = (res + fen[i]) % mod;
        i -= (-i & i);
    }
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vll v(n);
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        st.insert(v[i]);
    }

    map<ll, ll> comp;
    ll i = 1;
    for (auto e : st)
    {
        comp[e] = i;
        i++;
    }

    vector<ll> fen(st.size() + 1, 0);
    vector<ll> dp(n);
    for (ll i = 0; i < n; i++)
    {
        dp[i] = (1 + query(fen, comp[v[i]] - 1)) % mod;
        update(fen, fen[comp[v[i]]], fen[comp[v[i]]] + dp[i], comp[v[i]]);
    }

    ll ans = 0;
    for (ll i = 0; i < dp.size(); i++)
    {
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << '\n';
}