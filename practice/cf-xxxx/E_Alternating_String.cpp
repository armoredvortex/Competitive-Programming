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

    string s;
    cin >> s;

    if (n % 2 == 0)
    {
        vector<ll> even_idx(26, 0), odd_idx(26, 0);
        for (ll i = 0; i < n; i++)
        {
            if (i % 2)
            {
                odd_idx[s[i] - 'a']++;
            }
            else
            {
                even_idx[s[i] - 'a']++;
            }
        }

        cout << accumulate(all(even_idx), 0ll) - *max_element(all(even_idx)) + accumulate(all(odd_idx), 0ll) - *max_element(all(odd_idx)) << '\n';
    }
    else
    {
        ll ans = LONG_LONG_MAX;
        pair<vector<ll>, vector<ll>> pre(vector<ll>(26, 0), vector<ll>(26, 0)),
            post(vector<ll>(26, 0), vector<ll>(26, 0));

        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                post.first[s[i] - 'a']++;
            }
            else
            {
                post.second[s[i] - 'a']++;
            }
        }

        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                post.first[s[i] - 'a']--;
            }
            else
            {
                post.second[s[i] - 'a']--;
            }
            ll e_sum = 0, e_max = 0;
            ll o_sum = 0, o_max = 0;
            for (ll j = 0; j < 26; j++)
            {
                e_sum += post.second[j];
                e_sum += pre.first[j];
                e_max = max(e_max, post.second[j] + pre.first[j]);

                o_sum += post.first[j];
                o_sum += pre.second[j];
                o_max = max(o_max, post.first[j] + pre.second[j]);
            }

            ans = min(ans, e_sum + o_sum - e_max - o_max);
            if (i % 2 == 0)
            {
                pre.first[s[i] - 'a']++;
            }
            else
            {
                pre.second[s[i] - 'a']++;
            }
        }

        cout << ans + 1 << '\n';
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