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

map<ll, ll> factor(int n)
{
    map<ll, ll> ret;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n > 1)
    {
        ret[n]++;
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;
    map<map<ll, ll>, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        map<ll, ll> curr = factor(v[i]);
        for (auto &e : curr)
        {
            e.second %= k;
        }
        for (auto it = curr.begin(); it != curr.end();)
        {
            if ((*it).second == 0)
            {
                it = curr.erase(it);
            }
            else
            {
                ++it;
            }
        }

        // if (curr.size() == 0)
        // {
        //     ans += mp[{}];
        // }
        // else
        // {

        map<ll, ll> req;
        for (auto e : curr)
        {
            req[e.first] = (k - e.second + k) % k;
        }
        ans += mp[req];
        // }

        mp[curr]++;
    }
    cout << ans << '\n';
}