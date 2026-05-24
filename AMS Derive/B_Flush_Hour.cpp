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

    ll n, k, F;
    cin >> n >> k >> F;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    ll curr_time = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && i % k == 0)
        {
            curr_time += F;
        }
        curr_time += v[i].second;
        ans = max(ans, max(0ll, curr_time - v[i].first;
    }

    cout << ans;
}