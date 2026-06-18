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

ll rangeSum(ll l, ll r, vector<ll> &prefix)
{
    return prefix[r + 1] - prefix[l];
}

ll solve(ll l, ll r, ll sum, vector<vector<ll>> &dp, vector<ll> &prefix)
{
    if (l == r)
    {
        return 0;
    }

    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }

    ll ans = LONG_LONG_MAX;
    for (ll i = l; i <= r - 1; i++)
    {
        ans = min(ans, sum + solve(l, i, rangeSum(l, i, prefix), dp, prefix) +
                           solve(i + 1, r, rangeSum(i + 1, r, prefix), dp, prefix));
    }
    dp[l][r] = ans;
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    vll prefix(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + v[i];
    }

    cout << solve(0, n - 1, accumulate(v.begin(), v.end(), 0ll), dp, prefix);
}