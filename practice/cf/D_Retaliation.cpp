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
    ll d = v[1] - v[0];
    for (ll i = 0; i < n - 1; i++)
    {
        if (v[i + 1] - v[i] != d)
        {
            cout << "NO\n";
            return;
        }
    }
    if ((v[0] - d) % (n + 1) == 0)
    {
        ll b = (v[0] - d) / (n + 1);
        ll a = b + d;
        if (a >= 0 && b >= 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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