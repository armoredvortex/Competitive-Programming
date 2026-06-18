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

ll xorTilln(ll n)
{
    if (n % 4 == 0)
    {
        return n;
    }
    else if (n % 4 == 1)
    {
        return 1;
    }
    else if (n % 4 == 2)
    {
        return n + 1;
    }
    else
    {
        return 0;
    }
}

ll xorRange(ll l, ll r)
{
    return xorTilln(r) ^ xorTilln(l - 1);
}

void solve()
{
    ll l, r, i, k;
    cin >> l >> r >> i >> k;

    ll base = xorRange(l, r);
    ll twoi = 1 << i;

    ll n1 = max(0ll, (l - k + twoi - 1) / twoi);
    ll start = k + n1 * twoi;
    ll end = -1;
    if (r >= k)
    {
        ll n2 = (r - k) / twoi;
        end = k + n2 * twoi;
    }

    if (end >= start)
    {
        ll compressed_start = start >> i;
        ll compressed_end = end >> i;
        ll j = xorRange(compressed_start, compressed_end) << i;
        base ^= j;
        if ((compressed_end - compressed_start + 1) % 2 == 1)
        {
            base ^= (start & ((1 << i) - 1));
        }
    }
    cout << base << '\n';
    // cerr << base << ' ' << start << ' ' << end << '\n';
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