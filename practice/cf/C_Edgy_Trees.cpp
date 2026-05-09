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

const ll mod = 1000000007;
ll modpow(ll b, ll e)
{
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1)
            ans = ans * b % mod;
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> adj(n);

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if (w == 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vll visited(n, 0);
    vll compSizes;
    for (ll i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        ll sz = 0;
        visited[i] = 1;
        stack<ll> st;
        st.push(i);
        while (!st.empty())
        {
            auto e = st.top();
            st.pop();
            sz++;

            for (auto f : adj[e])
            {
                if (!visited[f])
                {
                    visited[f] = 1;
                    st.push(f);
                }
            }
        }
        compSizes.push_back(sz);
    }

    // cerr << compSizes;
    ll ans = modpow(n, k);
    for (auto e : compSizes)
    {
        ans = (mod + ans - modpow(e, k)) % mod;
    }
    cout << ans << '\n';
    return 0;
}