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

    ll n, mx;
    cin >> n >> mx;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll limit = (1 << n);
    vector<pair<ll, ll>> dp(limit);
    dp[0] = {1, 0};
    for (ll i = 1; i < limit; i++)
    {
        pair<ll, ll> best = {INT_MAX, INT_MAX};
        for (ll j = 0; j < n; j++)
        {
            if ((i & (1 << j)) == 0)
                continue;

            auto res = dp[i ^ (1 << j)];
            if (res.second + v[j] <= mx)
            {
                res.second += v[j];
            }
            else
            {
                res.first++;
                res.second = v[j];
            }
            best = min(res, best);
        }
        dp[i] = best;
    }

    cout << dp[(1 << n) - 1].first;
}