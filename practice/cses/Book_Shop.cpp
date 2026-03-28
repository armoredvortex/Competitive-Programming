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

    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - h[i - 1] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
            }
        }
    }
    cout << dp[n][x];
    // cerr << dp;
}