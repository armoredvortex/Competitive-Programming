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

const int MOD = 1000000000 + 7;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0ll));

    if (v[0] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][v[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] == 0)
        {
            for (int j = 1; j < m + 1; j++)
            {
                dp[i][j] = (dp[i - 1][j] % MOD + dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD) % MOD;
            }
        }
        else
        {
            dp[i][v[i]] = (dp[i - 1][v[i]] % MOD + dp[i - 1][v[i] - 1] % MOD + dp[i - 1][v[i] + 1] % MOD) % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i < m + 1; i++)
    {
        ans = (ans + dp[n - 1][i]) % MOD;
    }
    cout << ans;
}
