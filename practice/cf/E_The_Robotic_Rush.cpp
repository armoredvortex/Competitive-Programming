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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> robots(n);
    vector<ll> spikes(m);

    for (ll i = 0; i < n; i++)
    {
        cin >> robots[i];
    }

    for (ll i = 0; i < m; i++)
    {
        cin >> spikes[i];
    }

    sort(all(robots));
    sort(all(spikes));

    string s;
    cin >> s;
    ll mx = 0, mn = 0;
    ll sub = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
        {
            sub--;
        }
        else
        {
            sub++;
        }

        mx = max(mx, sub);
        mn = min(mn, sub);
    }

    
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