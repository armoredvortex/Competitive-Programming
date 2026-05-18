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

    int n;
    cin >> n;

    vector<ll> ct(1e5 + 10, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ct[a]++;
    }

    vector<ll> dp(1e5 + 10, 0);
    dp[0] = 0;
    dp[1] = ct[1];

    for (int i = 2; i < 1e5 + 5; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * ct[i]);
    }

    cout << *max_element(dp.begin(), dp.end());
}