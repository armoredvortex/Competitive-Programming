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
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(h + 1, vector<ll>(w + 1, 0));
    for (ll i = 1; i < h + 1; i++)
    {
        for (ll j = 1; j < w + 1; j++)
        {
            if (i == 1 && j == 1)
            {
                dp[i][j] = 1;
                continue;
            }
            if (grid[i - 1][j - 1] == '.')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp.back().back() << '\n';
}