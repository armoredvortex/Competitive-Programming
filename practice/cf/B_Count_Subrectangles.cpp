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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m, k;
    cin >> n >> m >> k;

    vll factors;
    for (ll i = 1; i <= sqrt(k); i++)
    {
        if (k % i == 0)
        {
            factors.push_back(i);
            if (k / i != i)
            {
                factors.push_back(k / i);
            }
        }
    }

    vll a(n), b(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vll ai, bi;
    ll ct = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            ct++;
        }
        else
        {
            if (ct)
            {
                ai.push_back(ct);
            }
            ct = 0;
        }
    }
    if (ct)
    {
        ai.push_back(ct);
    }
    ct = 0;
    for (ll i = 0; i < m; i++)
    {
        if (b[i] == 1)
        {
            ct++;
        }
        else
        {
            if (ct)
            {
                bi.push_back(ct);
            }
            ct = 0;
        }
    }
    if (ct)
    {
        bi.push_back(ct);
    }

    sort(all(ai));
    sort(all(bi));

    ll ans = 0;
    for (auto e : factors)
    {
        ll req = k / e;
        ll total = 0;
        for (ll i = 0; i < bi.size(); i++)
        {
            if (bi[i] - req + 1 > 0)
            {
                total += bi[i] - req + 1;
            }
        }

        for (ll i = 0; i < ai.size(); i++)
        {
            if (ai[i] - e + 1 > 0)
            {
                ans += total * (ai[i] - e + 1);
            }
        }
    }
    cout << ans << '\n';
}