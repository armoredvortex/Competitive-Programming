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
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    set<ll> st(v.begin(), v.end());

    ll ans = 1;
    vector<ll> vn;
    for (auto e : st)
    {
        vn.push_back(e);
    }

    // cerr << vn << '\n';

    for (int i = 0; i < vn.size() - 1; i++)
    {
        ll sub = 1;
        ll k = i;
        while (k < vn.size() - 1 && vn[k + 1] - vn[k] == 1)
        {
            sub++;
            k++;
        }

        ans = max(ans, sub);
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