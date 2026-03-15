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

    map<ll, ll> m;
    for (ll i = 0; i < n * n; i++)
    {
        ll a;
        cin >> a;
        m[a]++;
    }

    for (auto e : m)
    {
        if (e.second > n * n - n)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
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