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
        cin >> v[i];
    }

    ll sum = accumulate(v.begin(), v.end(), 0ll);
    map<ll, ll> mp;
    ll mx = 0;
    vll mad(n);
    for (ll i = 0; i < n; i++)
    {
        mp[v[i]]++;
        if (mp[v[i]] > 1 && v[i] > mx)
        {
            mx = v[i];
        }

        mad[i] = mx;
    }

    sum += accumulate(mad.begin(), mad.end(), 0ll);

    mp.clear();
    vll mad2(n);
    mx = 0;
    for (ll i = 0; i < n; i++)
    {
        mp[mad[i]]++;
        if (mp[mad[i]] > 1 && mad[i] > mx)
        {
            mx = mad[i];
        }
        mad2[i] = mx;
    }

    // sum << '\n';
    for (ll i = 0; i < n; i++)
    {
        sum += mad2[n - i - 1] * (i + 1);
    }

    cout << sum << '\n';
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