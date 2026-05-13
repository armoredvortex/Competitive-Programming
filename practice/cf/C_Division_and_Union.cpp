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

    vector<pair<pair<ll, ll>, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }

    sort(all(v));
    ll right = v[0].first.second;
    ll flag = -1;
    for (ll i = 0; i < n; i++)
    {
        if (right < v[i].first.first)
        {
            flag = i;
            break;
        }
        else
        {
            right = max(right, v[i].first.second);
        }
    }

    if (flag == -1)
    {
        cout << flag << '\n';
        return;
    }
    vll ans(n);
    for (ll i = 0; i < n; i++)
    {
        if (i < flag)
        {
            ans[v[i].second] = 1;
        }
        else
        {
            ans[v[i].second] = 2;
        }
    }

    for (auto e : ans)
    {
        cout << e << ' ';
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