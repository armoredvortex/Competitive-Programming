
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
    ll n = s.size();

    ll starti = -1;
    ll mxl = 0;

    ll flag = 1;
    for (ll i = n / 2; i >= 0 && flag; i--)
    {
        ll left = 0;
        ll ct = 0;
        while (left + i < n)
        {
            if (s[left] == '?' || s[left + i] == '?' || s[left] == s[left + i])
            {
                ct++;
            }
            else
            {
                ct = 0;
            }
            left++;
            if (ct == i)
            {
                starti = left - i;
                mxl = i;
                flag = 0;
                break;
            }
        }
    }
    // cerr << starti << ' ' << mxl << "\n";
    cout << 2 * mxl << '\n';
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