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
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    map<ll, vector<ll>> m1, m2;
    for (ll i = 0; i < n; i++)
    {
        m1[v[i].first].push_back(i);
        m2[v[i].second].push_back(i);
    }

    ll ans = n * (n - 1) * (n - 2) / 6;
    for (ll i = 0; i < n; i++)
    {
        auto &e1 = m1[v[i].first];
        auto &e2 = m2[v[i].second];
        // ll s1 = e1.end() - lower_bound(e1.begin(), e1.end(), i) - 1;
        // ll s2 = e2.end() - lower_bound(e2.begin(), e2.end(), i) - 1;
        ll s1 = e1.size() - 1;
        ll s2 = e2.size() - 1;
        ans -= s1 * s2;
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