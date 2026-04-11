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

    ll n, g;
    cin >> n >> g;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }

    sort(v.rbegin(), v.rend());

    ll right = -1;
    for (auto &e : v)
    {
        right = max(right, e.second - e.first);
    }
    ll left = 0;

    ll mid, ans = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;


        ll g_calc = 0;
        vector<ll> tttt;
        vector<pair<long long,long long>> tt;
        for (ll i = 0; i < n; i++)
        {
            ll curr_end = min(v[i].second, v[i].first + mid);
            tt.emplace_back(curr_end,v[i].first);
        }
        sort(all(tt));
        for(ll i=0; i<n; i++){
            ll curr_end = min(v[i].second, v[i].first+mid);
            int id = lower_bound(tt.begin(),tt.end(),make_pair(curr_end,v[i].first))-tt.begin();
            id = id-i+1;
            g_calc += id;
        }
        if (g_calc == g)
        {
            ans = mid;
            right = mid - 1;
        }
        else if (g_calc > g)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
}