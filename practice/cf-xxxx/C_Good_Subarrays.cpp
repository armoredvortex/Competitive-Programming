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
        char c;
        cin >> c;

        v[i] = c - '0';
    }

    vll pre(n + 1);
    pre[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i];
        pre[i + 1] += v[i];
    }

    vll mpre(n + 1);
    for (ll i = 1; i < n + 1; i++)
    {
        mpre[i] = pre[i] - i;
    }

    // cerr << pre << '\n'
    //      << mpre << '\n';

    map<ll, ll> m;
    ll ans = 0;
    for (ll i = 0; i < n + 1; i++)
    {
        ll req = pre[i] - i;

        ans += m[req];
        m[mpre[i]]++;
    }

    cout << ans << '\n';
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