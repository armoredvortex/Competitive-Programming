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

ll MOD = 1000000007;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;

    vll ways(n + 1, 1);
    ll ans = 0;
    for (ll i = 0; i < k - 1; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll k = j;
            ll temp = 0;

            while (k <= n)
            {
                // cerr << k << ' ';
                // ans = (ans + ways[k]) % (1000000009);
                temp = (temp + ways[k]) % MOD;
                k += j;
            }
            ways[j] = temp;
            // cerr << '\n';
        }
    }

    for (ll i = 0; i < n; i++)
    {
        ans = (ans + ways[i + 1]) % MOD;
    }
    cout << ans;

    return 0;
}

// 1
// 2
// 3

// 1 1
// 1 2
// 1 3
// 2 2
// 3 3

// 1 1 1
// 1 1 2
// 1 1 3
// 1 2 2
// 1 3 3
// 2 2 2
// 3 3 3