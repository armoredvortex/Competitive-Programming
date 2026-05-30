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
    string a, b;
    cin >> a >> b;
    a = 'X' + a;
    b = 'X' + b;
    vector<vector<ll>> dp(n + 1, vector<ll>(4, -1));
    dp[0][3] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        dp[i][0] = dp[i - 1][3];

        {
            ll mx = -1;
            if (i - 2 >= 0)
            {
                ll ct = 0;
                if (b[i] == 'A')
                    ct++;
                if (b[i - 1] == 'A')
                    ct++;
                if (a[i - 1] == 'A')
                    ct++;

                if (ct > 1)
                {
                    ct = 1;
                }
                else
                {
                    ct = 0;
                }

                if (dp[i - 2][3] != -1)
                {
                    mx = max(mx, ct + dp[i - 2][3]);
                }
            }
            if (i - 3 >= 0)
            {
                ll ct1 = 0, ct2 = 0;
                if (a[i - 3] == 'A')
                    ct1++;
                if (a[i - 2] == 'A')
                    ct1++;
                if (a[i - 1] == 'A')
                    ct1++;
                if (b[i - 2] == 'A')
                    ct2++;
                if (b[i - 1] == 'A')
                    ct2++;
                if (b[i] == 'A')
                    ct2++;
                if (ct1 > 1)
                {
                    ct1 = 1;
                }
                else
                {
                    ct1 = 0;
                }
                if (ct2 > 1)
                {
                    ct2 = 1;
                }
                else
                {
                    ct2 = 0;
                }

                if (dp[i - 3][1] != -1)
                {
                    mx = max(mx, ct1 + ct2 + dp[i - 3][1]);
                }
            }
            dp[i][1] = mx;
        }
        {
            ll mx = -1;
            if (i - 2 >= 0)
            {
                ll ct = 0;
                if (a[i] == 'A')
                    ct++;
                if (a[i - 1] == 'A')
                    ct++;
                if (b[i - 1] == 'A')
                    ct++;

                if (ct > 1)
                {
                    ct = 1;
                }
                else
                {
                    ct = 0;
                }

                if (dp[i - 2][3] != -1)
                {
                    mx = max(mx, ct + dp[i - 2][3]);
                }
            }
            if (i - 3 >= 0)
            {
                ll ct1 = 0, ct2 = 0;
                if (b[i - 3] == 'A')
                    ct1++;
                if (b[i - 2] == 'A')
                    ct1++;
                if (b[i - 1] == 'A')
                    ct1++;
                if (a[i - 2] == 'A')
                    ct2++;
                if (a[i - 1] == 'A')
                    ct2++;
                if (a[i] == 'A')
                    ct2++;
                if (ct1 > 1)
                {
                    ct1 = 1;
                }
                else
                {
                    ct1 = 0;
                }
                if (ct2 > 1)
                {
                    ct2 = 1;
                }
                else
                {
                    ct2 = 0;
                }

                if (dp[i - 3][2] != -1)
                {
                    mx = max(mx, ct1 + ct2 + dp[i - 3][2]);
                }
            }
            dp[i][2] = mx;
        }
        {
            ll mx = -1;
            if (i - 2 >= 0)
            {
                ll ct1 = 0, ct2 = 0;
                if (b[i - 2] == 'A')
                    ct1++;
                if (b[i - 1] == 'A')
                    ct1++;
                if (b[i] == 'A')
                    ct1++;
                if (a[i - 2] == 'A')
                    ct2++;
                if (a[i - 1] == 'A')
                    ct2++;
                if (a[i] == 'A')
                    ct2++;
                if (ct1 > 1)
                {
                    ct1 = 1;
                }
                else
                {
                    ct1 = 0;
                }
                if (ct2 > 1)
                {
                    ct2 = 1;
                }
                else
                {
                    ct2 = 0;
                }

                if (dp[i - 2][0] != -1)
                {
                    mx = max(mx, ct1 + ct2 + dp[i - 2][0]);
                }
            }
            if (i - 1 >= 0)
            {
                ll ct = 0;
                if (a[i - 1] == 'A')
                    ct++;
                if (a[i] == 'A')
                    ct++;
                if (b[i] == 'A')
                    ct++;
                if (ct > 1)
                {
                    ct = 1;
                }
                else
                {
                    ct = 0;
                }
                if (dp[i - 1][1] != -1)
                {
                    mx = max(mx, ct + dp[i - 1][1]);
                }
            }
            if (i - 1 >= 0)
            {
                ll ct = 0;
                if (b[i - 1] == 'A')
                    ct++;
                if (b[i] == 'A')
                    ct++;
                if (a[i] == 'A')
                    ct++;
                if (ct > 1)
                {
                    ct = 1;
                }
                else
                {
                    ct = 0;
                }
                if (dp[i - 1][2] != -1)
                {
                    mx = max(mx, ct + dp[i - 1][2]);
                }
            }

            dp[i][3] = mx;
        }
    }

    // cerr << dp;
    cout << dp.back().back() << "\n";
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