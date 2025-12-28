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

    ll n, x;
    cin >> n >> x;

    vll v(n), pre(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    pre[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i];
        pre[i + 1] += v[i];
    }

    map<ll, ll> m;
    ll ans = 0;
    for (ll i = 0; i < n + 1; i++)
    {
        ll curr = pre[i];
        ll req = curr - x;

        ans += m[req];
        m[curr]++;
    }
    cout << ans << '\n';
}