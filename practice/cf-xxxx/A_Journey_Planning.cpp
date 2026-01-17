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

    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<ll> c(n);
    for (ll i = 0; i < n; i++)
    {
        c[i] = b[i] - (i + 1);
    }

    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        m[c[i]] += c[i] + (i + 1);
    }

    ll max_b = LONG_LONG_MIN;
    for (auto e : m)
    {
        max_b = max(max_b, e.second);
    }
    cout << max_b << "\n";
    // cerr << c << '\n';
    // cerr << m;
}