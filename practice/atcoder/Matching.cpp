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

const ll mod = 1e9 + 7;

ll solve(ll men, ll women, vector<vector<ll>> &v, vector<ll> &dp, ll n)
{
    if (men == n)
    {
        return 1;
    }

    if (dp[women] != -1)
    {
        return dp[women];
    }
    ll ways = 0;
    for (ll i = 0; i < n; i++)
    {
        if ((women & (1 << i)) == 0 && v[men][i])
        {
            ways = (ways + solve(men + 1, women | (1 << i), v, dp, n)) % mod;
        }
    }
    dp[women] = ways;
    return ways;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<ll> dp(1 << n, -1);
    cout << solve(0, 0, v, dp, n);
}