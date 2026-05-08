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

    vll pre(n + 1, 0);
    for (ll i = 1; i < n + 1; i++)
    {
        pre[i] = v[i - 1] ^ pre[i - 1];
    }
    // cerr << pre << '\n';
    for (ll i = 1; i < pre.size() - 1; i++)
    {
        ll left = pre[i];
        ll right = pre.back() ^ pre[i];

        if (left == right)
        {
            cout << "YES\n";
            return;
        }
    }
    for (ll i = 1; i < pre.size() - 1; i++)
    {
        for (ll j = i + 1; j < pre.size() - 1; j++)
        {
            ll left = pre[i];
            ll mid = pre[j] ^ pre[i];
            ll right = pre.back() ^ pre[j];

            if (left == mid && left == right)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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