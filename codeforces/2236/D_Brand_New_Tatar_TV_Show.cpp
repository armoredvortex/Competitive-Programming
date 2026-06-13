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

bool checkGrp(vector<ll> &v)
{
    ll mx = *max_element(v.begin(), v.end());
    if (count(v.begin(), v.end(), mx) % 2 == 0)
    {
        return true;
    }
    else
    {
        if (count(v.begin(), v.end(), mx) != v.size())
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    vector<vector<ll>> grps(1);
    for (ll i = 0; i < n - 1; i++)
    {
        grps.back().push_back(v[i]);
        if (v[i + 1] - v[i] > k)
        {
            grps.push_back({});
        }
    }
    grps.back().push_back(v.back());

    for (auto &e : grps)
    {
        if (checkGrp(e))
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