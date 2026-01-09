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

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);

    ll left = v[0].second;
    ll ans = 1;

    for (ll i = 1; i < n; i++)
    {
        auto e = v[i];
        if (e.first >= left)
        {
            ans++;
            left = e.second;
        }
    }

    cout << ans;
}
