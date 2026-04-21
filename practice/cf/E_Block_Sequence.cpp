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

void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vll cost(n + 1, 0);
    for (ll i = n - 1; i >= 0; i--)
    {
        if (i + v[i] + 1 > n)
        {
            cost[i] = cost[i + 1] + 1;
        }
        else
        {
            if (cost[i + v[i] + 1] == 0)
            {
                continue;
            }
            else
            {
                cost[i] = min(cost[i + 1] + 1, cost[i + v[i] + 1]);
            }
        }
    }
    // cerr << cost << '\n';
    cout << cost[0] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--)
        solve();
}