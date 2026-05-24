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
    int n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll x = 0;
    for (ll i = 0; i < n; i++)
    {
        x += v[i] - 1;
    }

    if (x % 2 == 0)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Alice\n";
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