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

void solve()
{
    int n, k;
    cin >> k >> n;

    vector<int> v(k + 1);
    v[0] = 1;
    n--;
    int dir = 0;
    int ans = 1;
    while (n--)
    {
        if (dir == 0)
        {
            for (int i = 1; i < k; i++)
            {
                v[i] = (v[i] + v[i - 1]) % MOD;
            }

            for (auto e : v)
            {
                ans = (ans + e) % MOD;
            }
            dir = 1;
        }
        else
        {
            v[0] = 0;
            for (int i = k - 1; i >= 1; i--)
            {
                v[i] = (v[i] + v[i + 1]) % MOD;
            }
            for (auto e : v)
            {
                ans = (ans + e) % MOD;
            }
            dir = 0;
        }
        // cerr << v << '\n';
    }

    cout << ans << '\n';
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