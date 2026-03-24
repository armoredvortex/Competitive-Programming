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

vector<ll> factor(ll n)
{
    vector<ll> ret;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        ret.push_back(n);
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    map<ll, ll> mp;
    // cerr << factor(n);
    for (auto e : factor(n))
    {
        mp[e]++;
    }

    ll ans = 0;
    for (auto &e : mp)
    {
        ll ct = 1;
        while (e.second - ct >= 0)
        {
            ans++;
            e.second -= ct;
            ct++;
        }
    }
    cout << ans << '\n';
}