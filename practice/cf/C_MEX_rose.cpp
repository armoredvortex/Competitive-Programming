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
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(all(v));

    ll ans = 0;
    ll it = lower_bound(all(v), k) - v.begin();

    map<ll, ll> m;

    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }

    for (int i = 0; i < k; i++)
    {
        if (m[i] < 1)
        {
            if(m[v[it]] > 0){
                m[v[it]]--;
            }
            ans++;
        }
    }

    ans += m[k];

    cout << ans << '\n';
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