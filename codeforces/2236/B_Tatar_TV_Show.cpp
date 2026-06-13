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
    string s;
    cin >> s;
    for (ll i = 0; i + k < n; i++)
    {
        if (s[i] == '1')
        {
            s[i] = '0';
            if (s[i + k] == '0')
            {
                s[i + k] = '1';
            }
            else
            {
                s[i + k] = '0';
            }
        }
    }
    // cerr << s << "\n";
    if (count(s.begin(), s.end(), '0') == n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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