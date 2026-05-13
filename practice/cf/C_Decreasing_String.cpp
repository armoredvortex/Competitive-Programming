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

    ll left = 1, right = n;
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

    ll x = ans - 1;
    // cerr << x << '\n';
    left = 0;
    stack<char> st;
    ll ct = 0;
    while (ct != x)
    {
        if (st.empty())
        {
            st.push(s[left]);
            left++;
        }
        else
        {
            while (left < s.size() && st.top() <= s[left])
            {
                st.push(s[left]);
                left++;
            }

            if (left >= n)
            {
                st.pop();
                ct++;
            }
            else
            {
                st.pop();
                ct++;
            }
        }
    }

    string res;
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    while (left < s.size())
    {
        res += s[left];
        left++;
    }

    ll kkk = (ans - 1) * n - (ans - 1) * (ans - 2) / 2;
    cout << res[pos - kkk - 1];
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