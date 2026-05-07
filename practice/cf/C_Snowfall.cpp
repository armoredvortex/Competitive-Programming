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

    vector<vector<ll>> types(4);
    for (ll i = 0; i < n; i++)
    {
        if (v[i] % 6 == 0)
        {
            types[0].push_back(v[i]);
        }
        else if (v[i] % 3 == 0)
        {
            types[1].push_back(v[i]);
        }
        else if (v[i] % 2 == 0)
        {
            types[2].push_back(v[i]);
        }
        else
        {
            types[3].push_back(v[i]);
        }
    }

    vll ans;
    for (auto e : types[0])
    {
        ans.push_back(e);
    }
    for (auto e : types[1])
    {
        ans.push_back(e);
    }
    for (auto e : types[3])
    {
        ans.push_back(e);
    }
    for (auto e : types[2])
    {
        ans.push_back(e);
    }

    for (auto e : ans)
    {
        cout << e << ' ';
    }

    // ll score = 0;
    // for (ll i = 0; i < n; i++)
    // {
    //     ll prod = 1;
    //     for (ll j = i; j < n; j++)
    //     {
    //         prod *= ans[i];
    //         if (prod % 6 == 0)
    //         {
    //             score++;
    //         }
    //     }
    // }
    // cout << "\nscore: " << score << '\n';

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