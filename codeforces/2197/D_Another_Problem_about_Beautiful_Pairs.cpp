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

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;

    // set<pair<ll, ll>> st;
    for (ll i = 0; i < n; i++)
    {
        ll e = v[i];

        for (ll aj = 1; aj <= sqrt(n); aj++)
        {
            ll possible_j = e * aj + i;
            // cerr << "-->" << e << ' ' << possible_j << '\n';

            if (possible_j < n && e * v[possible_j] == possible_j - i)
            {
                // cerr << i << ' ' << possible_j << '\n';
                ans++;
            }

            if (e > sqrt(n))
            {
                possible_j = i - e * aj;
                // cerr << "-->" << e << ' ' << possible_j << '\n';

                if (possible_j >= 0 && e * v[possible_j] == i - possible_j)
                {
                    // cerr << i << ' ' << possible_j << '\n';
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
    return;
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