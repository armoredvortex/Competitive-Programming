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

const int MOD = 1e9 + 7;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int r, g;
    cin >> r >> g;
    ll h = 0;
    while (h * (h + 1) / 2 <= r + g)
    {
        h++;
    }
    h--;

    // int dp[2][r + 1];
    vector<vector<int>> dp(2, vector<int>(r + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= h; i++)
    {
        int curr = i % 2;
        int prev = (i - 1) % 2;
        for (int j = 0; j <= r; j++)
        {
            dp[curr][j] = (dp[prev][j]) % MOD;
            if (j - i >= 0)
                dp[curr][j] = (dp[curr][j] + dp[prev][j - i]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i <= r; i++)
    {
        if (h * (h + 1) / 2 - i <= g)
        {
            ans = (ans + dp[h % 2][i]) % MOD;
        }
    }
    cout << ans << '\n';
}