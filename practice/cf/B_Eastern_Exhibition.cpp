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

    vll x(n), y(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    sort(all(x));
    sort(all(y));

    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }

    vll prex(n + 1, 0), postx(n + 1, 0);
    vll prey(n + 1, 0), posty(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        prex[i + 1] = prex[i] + x[i];
        prey[i + 1] = prey[i] + y[i];
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        postx[i] = postx[i + 1] + x[i];
        posty[i] = posty[i + 1] + y[i];
    }

    ll mindx = LONG_LONG_MAX, mindy = LONG_LONG_MAX;
    ll mincx = -1, mincy = -1;
    for (ll i = 1; i < n; i++)
    {
        if (x[i] == x[i - 1])
        {
            continue;
        }
        if (i == n - i)
        {
            ll dist = prex[i] + postx[i];
            if (dist < mindx)
            {
                mindx = dist;
                mincx = x[i] - x[i - 1] + 1;
            }
        }
        else if (i < n - i)
        {
            ll diff = n - i - i;
            ll dist = prex[i] + postx[i] + diff * x[i];
            if (dist < mindx)
            {
                mindx = dist;
                mincx = 1;
            }
        }
        else
        {
            ll diff = abs(n - i - i);
            ll dist = prex[i] + postx[i] + diff * x[i - 1];
            if (dist < mindx)
            {
                mindx = dist;
                mincx = 1;
            }
        }
    }

    for (ll i = 1; i < n; i++)
    {
        if (y[i] == y[i - 1])
        {
            continue;
        }
        if (i == n - i)
        {
            ll dist = prey[i] + posty[i];
            if (dist < mindy)
            {
                mindy = dist;
                mincy = y[i] - y[i - 1] + 1;
            }
        }
        else if (i < n - i)
        {
            ll diff = n - i - i;
            ll dist = prey[i] + posty[i] + diff * y[i];
            if (dist < mindy)
            {
                mindy = dist;
                mincy = 1;
            }
        }
        else
        {
            ll diff = abs(n - i - i);
            ll dist = prey[i] + posty[i] + diff * y[i - 1];
            if (dist < mindy)
            {
                mindy = dist;
                mincy = 1;
            }
        }
    }

    if (mincx == -1)
    {
        mincx = 1;
    }
    if (mincy == -1)
    {
        mincy = 1;
    }
    cout << mincx * mincy << '\n';
    // cerr << mincx << ' ' << mincy << '\n';
    // cerr << prex << ' ' << postx << '\n';
    // cerr << prey << ' ' << posty;
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