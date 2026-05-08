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

    vector<ll> pwfl;

    ll fct = 1;
    for (ll i = 1; i < 15; i++)
    {
        fct *= i;
        pwfl.push_back(fct);
    }

    // cerr << pwfl.size();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        int ans = INT_MAX;
        for (unsigned long long i = 0; i < pow(2, 15); i++)
        {
            ll s = 0;
            for (int j = 0; j < pwfl.size(); j++)
            {
                if (i & (1 << j))
                {
                    s += pwfl[j];
                }
            }
            unsigned long long rem = n - s;
            ans = min(__popcount(rem) + __popcount(i), ans);
        }
        cout << ans << '\n';
    }
}