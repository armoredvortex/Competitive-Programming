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
    vector<pair<ll, ll>> pre(s.size() + 1);
    pre[0] = {0, 0};
    int ct0 = count(s.begin(), s.end(), '0');
    int ct1 = count(s.begin(), s.end(), '1');
    for (int i = 1; i <= s.size(); i++)
    {
        pre[i] = pre[i - 1];
        if (s[i - 1] == '0')
        {
            pre[i].first++;
        }
        else
        {
            pre[i].second++;
        }
    }
    // cerr << pre;
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i <= s.size(); i++)
    {
        ans = min(ans, pre[i].first + ct1 - pre[i].second);
        ans = min(ans, pre[i].second + ct0 - pre[i].first);
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