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
    vll v(n, -1);
    ll mx = 0;
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cout << "? " << mx + 1 << ' ' << i + 1 << '\n';
        cout.flush();
        cin >> a;
        cout << "? " << i + 1 << ' ' << mx + 1 << '\n';
        cout.flush();
        cin >> b;
        if (a > b)
        {
            v[mx] = a;
            mx = i;
        }
        else
        {
            v[i] = b;
        }
    }
    cout << "! ";
    for (auto e : v)
    {
        if (e == -1)
        {
            cout << n << ' ';
        }
        else
        {
            cout << e << ' ';
        }
    }
    cout << '\n';
    cout.flush();
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}