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

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    vector<pair<ll, ll>> movies(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), comp);

    ll ans = 0;
    multiset<ll> mp;
    for (int i = 0; i < k; i++)
    {
        mp.insert(0);
    }
    // cerr << movies << '\n';
    for (int i = 0; i < n; i++)
    {
        // cerr << mp;
        auto it = mp.upper_bound(movies[i].first);
        if (it != mp.begin())
        {
            mp.erase(--it);
            mp.insert(movies[i].second);
            ans++;
        }
    }

    cout << ans;
}