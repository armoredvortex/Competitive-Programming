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
    vector<pair<ll, ll>> v(n, {0, 0});
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }

    for (ll i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;

        v[x].second++;
        v[y].second++;
    }

    ll init = 0;
    for (ll i = 0; i < n; i++)
    {
        init += v[i].first;
    }

    sort(all(v));
    // for (auto e : v)
    // {
    //     cerr << e << ' ';
    // }
    // cerr << '\n';
    ll left = n - 1;
    cout << init << " ";
    for (ll i = 0; i < n - 2; i++)
    {
        while (v[left].second <= 1)
        {
            left--;
        }
        init += v[left].first;
        cout << init << ' ';
        v[left].second--;
    }
   
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