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
    vector<pair<ll, ll>> vp(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        vp[i] = {v[i], i};
    }

    sort(vp.begin(), vp.end());

    vll nge(n), pge(n);
    stack<pair<ll, ll>> st1, st2;
    for (ll i = 0; i < n; i++)
    {
        while (st1.size() && st1.top().first <= v[i])
        {
            st1.pop();
        }
        while (st2.size() && st2.top().first <= v[n - i - 1])
        {
            st2.pop();
        }
        if (st1.size())
        {
            pge[i] = st1.top().second;
        }
        else
        {
            pge[i] = -1;
        }

        if (st2.size())
        {
            nge[n - i - 1] = st2.top().second;
        }
        else
        {
            nge[n - i - 1] = -1;
        }
        st1.push({v[i], i});
        st2.push({v[n - i - 1], n - i - 1});
    }

    // cerr << pge << '\n'
    //      << nge << '\n';

    vll dp(n, 0);
    for (int j = n - 1; j >= 0; j--)
    {
        ll i = vp[j].second;
        if (nge[i] == -1 && pge[i] == -1)
        {
            dp[i] = 1;
        }
        else if (nge[i] == -1)
        {
            dp[i] = 1 + dp[pge[i]];
        }
        else if (pge[i] == -1)
        {
            dp[i] = 1 + dp[nge[i]];
        }
        else
        {
            dp[i] = 1 + max(dp[nge[i]], dp[pge[i]]);
        }
    }

    // cerr << dp;
    cout << *max_element(dp.begin(), dp.end());
}