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

    multiset<ll> a;
    vector<ll> b(m);

    for (ll i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        a.insert(k);
    }

    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    for (auto e : b)
    {
        auto it = a.upper_bound(e);
        if (it == a.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            it--;
            cout << *it << '\n';
            a.erase(it);
        }
    }
}