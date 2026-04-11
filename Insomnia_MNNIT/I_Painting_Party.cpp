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

    ll n, q;
    cin >> n >> q;

    vector<vector<pair<ll, ll>>> v(n);
    int parity = 0;
    for (ll i = 0; i < q; i++)
    {
        ll qi;
        cin >> qi;

        if (qi == 1)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            if (parity == 0)
            {
                v[a - 1].push_back({c, 1e6 - i});
                v[b - 1].push_back({-1 * c, 1e6 - i});
            }
            else
            {
                v[n - a].push_back({-1 * c, 1e6 - i});
                v[n - b].push_back({c, 1e6 - i});
            }
        }
        else
        {
            parity ^= 1;
        }
    }

    vector<ll> out(n);
    ll curr_color = 0;
    set<pair<ll, ll>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].first > 0)
            {
                st.insert({v[i][j].second, v[i][j].first});
            }
        }
        if (st.size() == 0)
        {
            curr_color = 0;
        }
        else
        {
            curr_color = (*st.begin()).second;
        }

        out[i] = curr_color;

        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].first < 0)
            {
                st.erase({v[i][j].second, -1 * v[i][j].first});
            }
        }
    }

    if (parity)
    {
        reverse(out.begin(), out.end());
    }

    for (auto e : out)
    {
        cout << e << ' ';
    }
    // cout << out;
    // for (auto e : v)
    // {
    //     for (auto f : e)
    //     {
    //         cerr << f << ' ';
    //     }
    //     cerr << '\n';
    // }
}