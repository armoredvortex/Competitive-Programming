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

    string a, b;
    cin >> a;
    cin >> b;
    int n = a.size(), m = b.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for (ll i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (ll j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = dp[i][j];
            }
            else
            {
                dp[i + 1][j + 1] = 1 + min({dp[i][j], dp[i][j + 1], dp[i + 1][j]});
            }
        }
    }
    // cerr << dp;
    cout << dp.back().back() << '\n';
}