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
    vll v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll l = 0, r = 0;
    set<ll> s;

    ll ans = 0;
    while (r < n)
    {
        auto e1 = v[r];

        if (s.find(e1) == s.end())
        {
            s.insert(e1);
            r++;
            ans = max(ans, r - l);
        }
        else
        {
            while (s.find(e1) != s.end())
            {
                s.erase(v[l]);
                l++;
            }
        }
    }

    cout << ans << '\n';
}