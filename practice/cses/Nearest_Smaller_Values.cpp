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

    stack<pair<ll, ll>> st;
    for (ll i = 0; i < n; i++)
    {

        while (!st.empty() && st.top().first >= v[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            cout << 0 << ' ';
        }
        else
        {
            cout << st.top().second + 1 << ' ';
        }

        st.push({v[i], i});
    }
}