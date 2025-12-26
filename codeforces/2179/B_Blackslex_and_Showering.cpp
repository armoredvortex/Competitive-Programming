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

    ll ss = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ss += abs(v[i + 1] - v[i]);
    }

    ll mss = ss;
    for (ll i = 1; i < n - 1; i++)
    {
        ll subss = (ss - abs(v[i] - v[i - 1]) - abs(v[i + 1] - v[i]) + abs(v[i + 1] - v[i - 1]));
        if (subss < mss)
        {
            mss = subss;
        }
    }

    mss = min(mss, min(ss - abs(v[1] - v[0]), ss - abs(v[n - 1] - v[n - 2])));
    cout << mss << '\n';
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