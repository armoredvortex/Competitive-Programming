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

    int sheep = count(all(s), '*');

    vector<int> pre(n + 1, 0), prec(n + 1, 0), post(n + 1, 0), postc(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            pre[i + 1] = pre[i] + i;
            prec[i + 1] = pre[i] + 1;
        }
        else
        {
            pre[i + 1] = pre[i];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            post[i] = i + post[i + 1];
            postc[i] = postc[i + 1] + 1;
        }
        else
        {
            postc[i] = postc[i + 1];
        }
    }
    cerr << pre << '\n'
         << prec << '\n'
         << post << '\n'
         << postc << '\n';

    int window_sum = 0, window_count = 0;
    int l = 0;
    int r;
    for (r = 0; r < sheep; r++)
    {
        if (s[r] == '*')
        {
            window_count++;
            window_sum += r;
        }
    }
    r--;
    int ans = LONG_LONG_MAX;
    while (r < n)
    {
        int calc = 0;
        calc += prec[l] * l - pre[l];   // move all till left boundary
        calc += post[r] - postc[r] * r; // move all till right boundry

        int winl = l + prec[l];
        int winr = r - postc[r];

        int win_ideal = r * (r + 1) / 2 - l * (l - 1) / 2;
        calc +=                                      
        ans = min(ans, calc);
        if (s[l] == '*')
        {
            window_count--;
            window_sum -= l;
        }
        l++;
        r++;
        if (s[r] == '*')
        {
            window_count++;
            window_sum += r;
        }
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