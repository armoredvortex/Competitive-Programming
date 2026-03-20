#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m, k;
    cin >> n >> m >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<pair<ll, ll>> d(n - 1);
    for (ll i = 0; i < n - 1; i++)
    {
        d[i].first = v[i + 1] - v[i];
        // if (d[i].first == 1)
        // {
        //     d[i].first = LONG_LONG_MAX;
        // }
        d[i].second = i;
    }

    sort(all(d));
    // for (auto e : d)
    // {
    //     cerr << e.first << ' ';
    // }

    vll done(n, 0);
    ll ans = n;
    for (ll i = 0; i < n - k; i++)
    {
        ans += d[i].first - 1;
        // if (done[d[i].second] + done[d[i].second + 1] == 2)
        // {
        //     ans += d[i].first;
        // }
        // else
        // {
        //     ans += d[i].first - 1;
        //     done[d[i].second] = 1;
        //     done[d[i].second + 1] = 1;
        // }
    }
    cout << ans << '\n';
}