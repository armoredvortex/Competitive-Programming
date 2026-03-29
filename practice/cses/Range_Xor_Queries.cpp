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

    vll pre(n + 1);
    pre[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] ^ v[i];
    }

    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;

        cout << (pre[r] ^ pre[l - 1]) << '\n';
    }
}