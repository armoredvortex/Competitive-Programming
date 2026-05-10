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
    for (ll i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] ^ v[i];
    }

    cerr << pre << '\n';

    string s;
    cin >> s;

    ll oz = 0, zz = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            oz ^= v[i];
        }
        else
        {
            zz ^= v[i];
        }
    }

    cerr << oz << ' ' << zz << '\n';

    ll q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 2)
        {
            ll tp;
            cin >> tp;

            if (tp == 0)
            {
                cout << zz << ' ';
            }
            else
            {
                cout << oz << ' ';
            }
        }
        else
        {
            ll l, r;
            cin >> l >> r;

  
            ll k = pre[r] ^ pre[l - 1];
            oz ^= k;
            zz ^= k;
        }
    }
    cout << '\n';
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