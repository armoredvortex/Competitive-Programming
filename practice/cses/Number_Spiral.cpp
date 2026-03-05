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
    ll r, c;
    cin >> r >> c;

    ll jss = max(r, c) - 1;
    ll done = jss * jss;
    if (jss % 2 == 1)
    {
        if (r <= c)
        {
            cout << done + r << '\n';
            return;
        }
        else
        {
            cout << done + r + r - c << '\n';
            return;
        }
    }
    else
    {
        if (c <= r)
        {
            cout << done + c << '\n';
            return;
        }
        else
        {
            cout << done + c + c - r << '\n';
            return;
        }
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