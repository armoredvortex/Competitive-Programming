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
    ll a, b, k;
    cin >> a >> b >> k;
    vector<pair<int, int>> vp(k);
    vector<int> degA(a, 0), degB(b, 0);
    for (ll i = 0; i < k; i++)
    {
        cin >> vp[i].first;
        degA[--vp[i].first]++;
    }
    for (ll i = 0; i < k; i++)
    {
        cin >> vp[i].second;
        degB[--vp[i].second]++;
    }

    ll ans = 0;
    for (auto e : vp)
    {
        ans += (k - degA[e.first] - degB[e.second] + 1);
    }

    cout << ans / 2 << '\n';
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