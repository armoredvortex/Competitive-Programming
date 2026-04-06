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

    vll ct1;

    ll ct = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == 1)
        {
            ct++;
        }
        else
        {
            if (ct)
            {
                ct1.push_back(ct);
            }
            ct = 0;
        }
    }
    if (ct)
    {
        ct1.push_back(ct);
    }
    ct = 0;

    ll ans = v[0];
    for (int i = 0; i < ct1.size(); i++)
    {
        ans += (ct1[i]) / 3;
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