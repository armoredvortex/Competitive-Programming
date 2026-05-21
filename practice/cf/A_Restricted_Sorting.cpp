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
    vll v(n), vs(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        vs[i] = v[i];
    }

    sort(vs.begin(), vs.end());

    vll unsorted;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] != vs[i])
        {
            unsorted.push_back(vs[i]);
        }
    }

    if (!unsorted.size())
    {
        cout << -1 << '\n';
        return;
    }
    ll ans = -1;
    for (ll i = 0; i < unsorted.size() - 1; i++)
    {
        ans = 
    }

    cout << ans << '\n';
    return;
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