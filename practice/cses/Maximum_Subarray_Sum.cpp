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

    vector<ll> v(n), prefix(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll mxxx = *max_element(all(v));
    if (mxxx < 0)
    {
        cout << mxxx;
        return 0;
    }

    for (ll i = 0; i < n; i++)
    {
        prefix[i + 1] = v[i] + prefix[i];
    }

    ll m = 0;
    ll mx = 0;
    for (ll i = 0; i < n; i++)
    {
        m = min(m, prefix[i]);
        mx = max(prefix[i + 1] - m, mx);
    }

    cout << mx;
}