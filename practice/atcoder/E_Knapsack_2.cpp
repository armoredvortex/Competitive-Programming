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

vector<pair<ll, ll>> v;
map<pair<ll, ll>, ll> dp;
// ll dp[105][1000000];

ll n, w;

ll solve(ll i, ll w)
{
    if (i >= n || w <= 0)
    {
        return 0;
    }

    if (dp.find({i, w}) != dp.end())
    {
        return dp[{i, w}];
    }

    if (v[i].first <= w)
    {
        dp[{i, w}] = max(solve(i + 1, w), v[i].second + solve(i + 1, w - v[i].first));
    }
    else
    {
        dp[{i, w}] = solve(i + 1, w);
    }
    // cerr << i << ' ' << w << ' ' << dp[i][w] << '\n';
    return dp[{i, w}];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    // for (ll i = 0; i < 105; i++)
    // {
    //     for (ll j = 0; j < 100010; j++)
    //     {
    //         dp[i][j] = -1;
    //     }
    // }

    cin >> n >> w;
    v.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    cout << solve(0, w);
}

// State: Available wt, points collected