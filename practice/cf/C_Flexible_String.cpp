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
    ll n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    // O(1)
    vector<char> charset;
    for (int i = 0; i < n; i++)
    {
        if (find(charset.begin(), charset.end(), a[i]) == charset.end())
        {
            charset.push_back(a[i]);
        }
    }

    ll ans = 0;
    for (unsigned int i = 0; i < (1 << charset.size()); i++)
    {
        if (__popcount(i) > k)
            continue;

        vector<char> sub(26, 0);
        for (int j = 0; j < charset.size(); j++)
        {
            if (i & (1 << j))
            {
                sub[charset[j] - 'a'] = 1;
            }
        }

        ll sub_ans = 0;
        ll left = 0, right = 0;
        while (right < n)
        {
            if (sub[a[right] - 'a'] || a[right] == b[right])
            {
                sub_ans += (right - left + 1);
            }
            else
            {
                left = right + 1;
            }
            right++;
        }

        ans = max(ans, sub_ans);
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