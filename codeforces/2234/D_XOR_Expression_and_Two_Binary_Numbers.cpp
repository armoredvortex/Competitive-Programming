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
    ll n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    string c(n, '0');
    for (ll i = 0; i < n; i++)
    {
        c[i] = '0' + (a[i] - '0') ^ (b[i] - '0');
    }

    ll aval = count(a.begin(), a.end(), '1') * count(a.begin(), a.end(), '0');
    ll bval = count(b.begin(), b.end(), '1') * count(b.begin(), b.end(), '0');
    ll cval = count(c.begin(), c.end(), '1') * count(c.begin(), c.end(), '0');

    ll total = (1ll << k) + 1;
    ll cct = total / 3;
    cout << (aval + bval) * (total - cct) / 2 + cval * cct;

    cout << '\n';
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