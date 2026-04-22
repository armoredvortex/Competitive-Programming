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

const int MOD = 1000000007;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vector<int> ans(1000010);
    vector<vector<ll>> dp(1000010, vector<ll>(2));
    dp[0] = {1, 1};
    for (int i = 1; i < 1000010; i++)
    {
        dp[i][0] = ((dp[i - 1][0] * 4ll) % MOD + (dp[i - 1][1]) % MOD) % MOD;
        dp[i][1] = ((dp[i - 1][1] * 2ll) % MOD + (dp[i - 1][0] % MOD)) % MOD;
        ans[i] = (dp[i][0] + dp[i][1]) % MOD;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << ans[n - 1] << '\n';
        }
    }
}