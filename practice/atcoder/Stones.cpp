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

    ll n, k;
    cin >> n >> k;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vll dp(k + 1, 0);
    for (ll i = 0; i < k + 1; i++)
    {
        if (dp[i] == 0)
        {
            for (ll j = 0; j < n; j++)
            {
                if (i + v[j] < k + 1)
                {
                    dp[i + v[j]] = 1;
                }
            }
        }
    }

    if (dp.back() == 0)
    {
        cout << "Second";
    }
    else
    {
        cout << "First";
    }
}