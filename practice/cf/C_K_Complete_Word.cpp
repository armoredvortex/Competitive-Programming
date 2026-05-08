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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<ll>> adj(n);
    set<pair<ll, ll>> edges;

    for (ll i = 0; i < n / 2; i++)
    {
        edges.insert({i, n - i - 1});
    }

    for (ll i = 0; i < n - k; i++)
    {
        edges.insert({i, i + k});
    }

    for (auto e : edges)
    {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    // cerr << adj;

    ll ans = 0;
    vll visited(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        map<char, ll> ct;
        stack<ll> st;
        st.push(i);
        visited[i] = 1;
        while (!st.empty())
        {
            auto e = st.top();
            ct[s[e]]++;
            st.pop();

            for (auto f : adj[e])
            {
                if (!visited[f])
                {
                    visited[f] = 1;
                    st.push(f);
                }
            }
        }
        // cerr << ct;
        ll mx = 0;
        ll sum = 0;
        for (auto e : ct)
        {
            sum += e.second;
            if (e.second > mx)
            {
                mx = e.second;
            }
        }
        ans += sum - mx;
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