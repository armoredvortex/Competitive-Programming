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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }

    vector<ll> dp(n + 1, 0);
    dp[v[0].first] = v[0].second;
    for (ll i = 1; i < n; i++)
    {
        vector<ll> dp_new = dp;
        ll mx = 0;
        for (ll j = 0; j < n + 1; j++)
        {
            mx = max(mx, dp[j]);
            if (j == v[i].first)
            {
                dp_new[j] = max(v[i].second + mx, dp[j]);
            }
            else
            {
                dp_new[j] = max(mx, dp[j]);
            }
        }
        dp = dp_new;
    }
    cout << dp[v.back().first];
}