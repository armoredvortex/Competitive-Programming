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

    // precompute
    ll JJ = 5;
    vector<vector<ll>> s(JJ, vector<ll>(n + 1, 0));
    for (ll i = 0; i < JJ; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            auto e = v[j];
            s[i][j + 1] = s[i][j];
            if ((e & (1 << i)))
            {
                s[i][j + 1]++;
            }
        }
    }
    cerr << s;
    // for (auto e : s)
    // {
    //     for (auto f : e)
    //     {
    //         cerr << f << ' ';
    //     }
    //     cerr << '\n';
    // }

    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll l, k;
        cin >> l >> k;

        ll m = -1;
        // for (ll i = 0; i < __countl_zero(k); i++)
        // {
        // }
    }
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