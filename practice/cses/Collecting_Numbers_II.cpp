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

    ll n, m;
    cin >> n >> m;

    map<ll, ll> mp;
    mp[0] = -1;
    mp[n + 1] = n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]] = i;
    }

    ll rounds = 1;
    ll left = mp[1];
    while (v[left] != n)
    {
        ll next = mp[v[left] + 1];
        if (next < left)
        {
            rounds++;
        }
        left = next;
    }
    cerr << "initial = " << rounds << '\n';

    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;

        if (x < mp[v[x] - 1] && mp[v[x] - 1] < y)
        {
            rounds--;
        }
        if (x > mp[v[x] - 1] && mp[v[x] - 1] > y)
        {
            rounds++;
        }
        if (y < mp[v[y] - 1] && mp[v[y] - 1] < x)
        {
            rounds--;
        }
        if (y > mp[v[y] - 1] && mp[v[y] - 1] > x)
        {
            rounds++;
        }
        cout << rounds << '\n';
    }

    return 0;
}