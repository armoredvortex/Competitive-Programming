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

    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        mp[a]++;
    }

    vll v;
    for (auto e : mp)
    {
        v.push_back(e.second);
    }

    reverse(v.begin(), v.end());
    for (auto e : v)
    {
        if (e % 2)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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