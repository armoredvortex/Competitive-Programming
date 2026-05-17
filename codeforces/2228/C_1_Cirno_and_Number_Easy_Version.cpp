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
    ll a, n;
    cin >> a >> n;

    vector<ll> d(n);
    for (ll i = 0; i < n; i++)
        cin >> d[i];
    sort(d.begin(), d.end());

    vector<int> digits;
    ll acpy = a;

    if (acpy == 0)
        digits.push_back(0);
    while (acpy)
    {
        digits.push_back(acpy % 10);
        acpy /= 10;
    }
    if (a != 0)
        reverse(digits.begin(), digits.end());

    ll ans = LONG_LONG_MAX;

    int i = 0;
    while (i < digits.size() && (digits[i] == d[0] || digits[i] == d[1]))
    {
        i++;
    }

    if (i == digits.size())
    {
        ans = 0;
    }
    else
    {
        for (int k = i; k >= 0; k--)
        {
            if (digits[k] > d[0])
            {
                string s = "";
                for (int j = 0; j < k; j++)
                {
                    s += to_string(digits[j]);
                }
                s += to_string((digits[k] > d[1]) ? d[1] : d[0]);
                for (int j = k + 1; j < digits.size(); j++)
                {
                    s += to_string(d[1]);
                }
                ans = min(ans, abs(a - stoll(s)));
                break;
            }
        }
        if (digits.size() > 1)
        {
            string s(digits.size() - 1, '0' + d[1]);
            ans = min(ans, abs(a - stoll(s)));
        }

        for (int k = i; k >= 0; k--)
        {
            if (digits[k] < d[1])
            {
                string s = "";
                for (int j = 0; j < k; j++)
                {
                    s += to_string(digits[j]);
                }
                s += to_string((digits[k] < d[0]) ? d[0] : d[1]);
                for (int j = k + 1; j < digits.size(); j++)
                {
                    s += to_string(d[0]);
                }
                ans = min(ans, abs(a - stoll(s)));
                break;
            }
        }
        string s = (d[0] == 0) ? to_string(d[1]) : to_string(d[0]);
        s += string(digits.size() + (d[0] == 0 ? 0 : 1), '0' + d[0]);
        ans = min(ans, abs(a - stoll(s)));
    }

    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}