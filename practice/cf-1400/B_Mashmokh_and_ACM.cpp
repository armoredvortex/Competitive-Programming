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

    map<int, int> mp;
    mp[1]++;

    // cerr << factor(6);
    for (ll i = 1; i <= k; i++)
    {
        map<int, int> nmp;
        for (ll j = 1; j < n + 1; j++)
        {
            for (int i = 1; i * j <= n; i++)
            {
                nmp[i * j] = (nmp[i * j] + mp[j]) % MOD;
            }
        }
        // cerr << nmp << '\n';
        mp = nmp;
    }

    ll total = 0;
    for (auto e : mp)
    {
        total = (total + e.second) % MOD;
    }
    cout << total << '\n';
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