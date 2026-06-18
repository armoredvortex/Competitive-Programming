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
    ll a = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        a ^= v[i];
    }

    if (((x % 2 == y % 2) && (a % 2 == 0)) || ((x % 2 != y % 2) && (a % 2 == 1)))
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
    }
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