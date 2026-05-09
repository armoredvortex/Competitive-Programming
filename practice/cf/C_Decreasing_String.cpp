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
    string s;
    cin >> s;
    ll pos;
    cin >> pos;

    ll n = s.size();

    ll left = 1, right = n * (n + 1) / 2;
    ll mid;
    ll ans = -1;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        ll total = n * mid - (mid * (mid - 1)) / 2;

        if (total < pos)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            ans = mid;
        }
    }

    // cerr << ans << '\n';
    ll x = ans - 1;
    // cerr << x << '\n';

    stack<char> st;
    ll ct = 0;
    ll ptr = 0;
    while (ptr < n - 1 && ct != x)
    {
        if (s[ptr + 1] > s[ptr])
        {
            st.push(s[ptr]);
            ptr++;
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