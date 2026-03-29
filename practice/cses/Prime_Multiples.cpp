#include <bits/stdc++.h>
#include <bit>
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

    vll v(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;
    for (ll i = 1; i <= (1ll << k) - 1; i++)
    {
        if (__popcount((unsigned int)i) % 2)
        {
            __int128_t l = 1;
            for (ll j = 0; j < k; j++)
            {
                if ((i & (1 << j)))
                {
                    l *= v[j];
                }
                if (l > n)
                {
                    break;
                }
            }
            ans += n / l;
        }
        else
        {
            __int128_t l = 1;
            for (ll j = 0; j < k; j++)
            {
                if ((i & (1 << j)))
                {
                    l *= v[j];
                }
                if (l > n)
                {
                    break;
                }
            }
            ans -= n / l;
        }
    }

    cout << ans << '\n';
}