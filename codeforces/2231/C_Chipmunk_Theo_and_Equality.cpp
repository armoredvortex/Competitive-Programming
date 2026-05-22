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

    sort(all(v));

    set<ll> st;
    st.insert(1);
    st.insert(2);
    ll a = v[0];
    while (a != 1)
    {
        st.insert(a);
        if (a % 2)
        {
            a++;
        }
        else
        {
            a /= 2;
        }
    }

    for (int i = 1; i < n; i++)
    {
        set<int> stnew;
        stnew.insert(1);
        ll a = v[i];
        ll ct = 0;
        if (a == 1)
        {
            stnew.insert(2);
            continue;
        }
        while (a != 1)
        {
            stnew.insert(a);
            ct++;
            if (a % 2)
            {
                a++;
            }
            else
            {
                a /= 2;
            }
        }
        // cerr << a << '\n';
        for (auto it = st.begin(); it != st.end();)
        {
            if (stnew.find(*it) == stnew.end())
            {
                it = st.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    // cerr << st << '\n';
    long long ans = LONG_LONG_MAX;
    for (auto e : st)
    {
        ll suba = 0;
        for (int i = 0; i < n; i++)
        {
            ll a = v[i];
            while (a != e)
            {
                suba++;
                if (a % 2)
                {
                    a++;
                }
                else
                {
                    a /= 2;
                }
            }
        }
        ans = min(ans, suba);
    }
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