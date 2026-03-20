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

    ll n;
    cin >> n;

    vll v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int sz = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int a = v[i];
        for (int j = i; j < n; j++)
        {
            // cerr << i << ' ' << j << '\n';
            a = gcd(a, v[j]);
            // cerr << a << '\n';
            if (a == 1)
            {
                sz = min(sz, j - i + 1);
                break;
            }
        }
    }

    if (sz == INT_MAX)
    {
        cout << -1 << '\n';
        return 0;
    }

    if (find(v.begin(), v.end(), 1) != v.end())
    {
        cout << n - count(v.begin(), v.end(), 1) << '\n';
        return 0;
    }
    cout << sz - 2 + n << '\n';
    // cout << max(0, res) << '\n';
}
