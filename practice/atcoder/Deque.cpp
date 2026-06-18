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

ll solve(ll l, ll r, vector<ll> &v, vector<vector<ll>> &dp)
{
    if (r < l)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }

    dp[l][r] = max(v[l] + min(solve(l + 2, r, v, dp), solve(l + 1, r - 1, v, dp)),
                   v[r] + min(solve(l + 1, r - 1, v, dp), solve(l, r - 2, v, dp)));
    return dp[l][r];
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

    for (ll i = 0; i < n; i++)
    {
        dp[i][i] = v[i];
    }

    ll acc = accumulate(v.begin(), v.end(), 0ll);
    cout << 2 * solve(0, n - 1, v, dp) - acc;
}