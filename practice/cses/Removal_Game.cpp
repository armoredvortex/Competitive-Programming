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
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
    {
        dp[i][i] = v[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(v[i], v[i + 1]);
    }
    for (ll k = 2; k < n; k++)
    {
        for (ll i = 0; i + k < n; i++)
        {
            int j = i + k;
            dp[i][j] = max(v[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), v[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }

    // cerr << dp;

    cout << dp[0][n - 1];
}