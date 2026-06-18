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

double solve(ll a, ll b, ll c, ll n, vector<vector<vector<double>>> &dp)
{
    if (dp[a][b][c] != -1)
    {
        return dp[a][b][c];
    }
    ll ct = a + 2 * b + 3 * c;
    double exp = 0;
    if (a)
    {
        exp += a * (solve(a - 1, b, c, n, dp)) / n;
    }
    if (b)
    {
        exp += b * (solve(a + 1, b - 1, c, n, dp)) / n;
    }
    if (c)
    {
        exp += c * (solve(a, b + 1, c - 1, n, dp)) / n;
    }
    exp = n * (1 + exp) / (a + b + c);
    dp[a][b][c] = exp;
    return exp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vector<vector<vector<double>>> dp(301, vector<vector<double>>(301, vector<double>(301, -1)));
    dp[0][0][0] = 0;
    vector<ll> ct(3, 0);
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        a--;
        ct[a]++;
    }

    cout << fixed << setprecision(10);
    cout << solve(ct[0], ct[1], ct[2], n, dp);
}