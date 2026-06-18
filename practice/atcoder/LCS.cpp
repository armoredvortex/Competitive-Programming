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
    cin >> a >> b;
    ll n = a.size();
    ll m = b.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = 1 + dp[i][j];
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    ll i = n, j = m;
    vector<char> res;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            res.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j] == dp[i - 1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(res.begin(), res.end());
    for (auto e : res)
    {
        cout << e;
    }
}