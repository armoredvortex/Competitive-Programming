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

    ll n, q;
    cin >> n >> q;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<ll>> rq(n, vector<ll>(log2(n) + 1, 0));

    for (ll i = 0; i < n; i++)
    {
        rq[i][0] = v[i];
    }

    for (ll j = 1; j < log2(n) + 1; j++)
    {
        for (ll i = 0; i + (1 << j) - 1 < n; i++)
        {
            rq[i][j] = min(rq[i][j - 1], rq[i + (1 << j) - (1 << (j - 1))][j - 1]);
        }
    }

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        int sz = r - l + 1;
        if (sz == (1 << (ll)log2(sz)))
        {
            cout << rq[l][log2(sz)] << "\n";
        }
        else
        {
            cout << min(rq[l][log2(sz)], rq[r + 1 - (1 << (ll)log2(sz))][log2(sz)]) << '\n';
        }
    }
}