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

    ll n;
    cin >> n;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<ll> pv(n + 1), ng(n + 1);

    pv[0] = 0;
    ng[0] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        pv[i] = pv[i - 1];
        ng[i] = ng[i - 1];
        if (v[i - 1] > 0)
        {
            pv[i]++;
        }
        else
        {
            ng[i]++;
        }
    }

    // cerr << pv << '\n';
    // cerr << ng << '\n';

    ll ansp = 0;
    ll ev = 0, odd = 0;
    for (int i = 0; i < ng.size(); i++)
    {
        if (ng[i] % 2 == 0)
        {
            ansp += ev;
            ev++;
        }
        else
        {
            ansp += odd;
            odd++;
        }
    }
    cout << n * (n + 1) / 2 - ansp << ' ' << ansp << '\n';
}