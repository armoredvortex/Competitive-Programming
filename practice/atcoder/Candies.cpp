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

ll solve(ll i, ll k, vll &a, vector<vector<ll>> &dp)
{
    if (i == a.size() && k == 0)
    {
        return 1;
    }
    else if (i == a.size())
    {
        return 0;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }

    ll ans = 0;
    for (ll j = 0; j <= min(k, a[i]); j++)
    {
        ans = (ans + solve(i + 1, k - j, a, dp)) % mod;
    }
    dp[i][k] = ans;

    return dp[i][k];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));
    cout << solve(0, k, a, dp) << '\n';
}