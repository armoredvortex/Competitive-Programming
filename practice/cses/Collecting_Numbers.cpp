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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<ll, ll> positions;
    for (ll i = 0; i < n; i++)
    {
        positions[v[i]] = i;
    }

    ll ans = 1;
    ll ptr = positions[1];

    for (ll i = 2; i < n + 1; i++)
    {
        auto e = positions[i];
        if (e < ptr)
        {
            // cerr << i << ' ';
            ans++;
        }
        ptr = e;
    }
    cout << ans;
}