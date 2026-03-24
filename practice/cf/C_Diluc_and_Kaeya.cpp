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
    string s;
    cin >> s;

    map<pair<ll, ll>, ll> mp;

    pair<ll, ll> ct = {0, 0};
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'D')
        {
            ct.first++;
        }
        else
        {
            ct.second++;
        }

        ll g = gcd(ct.first, ct.second);
        pair<ll, ll> new_ct = {ct.first / g, ct.second / g};
        cout << mp[new_ct] + 1 << ' ';
        mp[new_ct]++;
    }
    cout << "\n";
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