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
    ll n, x, y;

    cin >> n >> x >> y;

    vll v(n);
    for (ll i = y - 1; i < x; i++)
    {
        v[i] = 1;
    }

    ll k = -1;
    for (ll i = x; i < n; i++)
    {
        v[i] = k;
        k *= -1;
    }

    k = -1;
    for (ll i = y - 2; i >= 0; i--)
    {
        v[i] = k;
        k *= -1;
    }

    for (auto e : v)
    {
        cout << e << ' ';
    }
    cout << '\n';
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