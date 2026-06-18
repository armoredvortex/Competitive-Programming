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

const int N = 1e5;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<ll> val(N + 10, 1e15);
    val[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = N; j >= v[i].second; j--)
        {
            val[j] = min(val[j], val[j - v[i].second] + v[i].first);
        }
    }

    // cerr << val;
    ll ans = -1;
    for (ll i = 0; i < val.size(); i++)
    {
        if (val[i] <= w)
        {
            ans = i;
        }
    }

    cout << ans;
}