#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

// #ifndef ONLINE_JUDGE
// #include "debugging.h"
// #endif

vector<vector<int>> dp;

int sol(int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (dp[j][i] != -1)
    {
        return dp[j][i];
    }

    int ans = INT_MAX;
    for (int k = 1; k < i; k++)
    {
        ans = min(ans, sol(i - k, j) + sol(k, j));
    }
    for (int k = 1; k < j; k++)
    {
        ans = min(ans, sol(i, j - k) + sol(i, k));
    }
    dp[i][j] = 1 + ans;
    return dp[i][j];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;
    dp.assign(510, vector<int>(510, -1));

    cout << sol(n, m);
}