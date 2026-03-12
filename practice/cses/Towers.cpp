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

    ll ct = 0;

    multiset<ll> st;
    for (ll i = 0; i < n; i++)
    {
        auto e = v[i];

        if (st.upper_bound(e) == st.end())
        {
            st.insert(e);
            ct++;
        }
        else
        {
            st.erase(st.upper_bound(e));
            st.insert(e);
        }
    }
    cout << ct << '\n';
}