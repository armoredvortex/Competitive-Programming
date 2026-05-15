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

    for (int i = 0; i < k; i++)
    {
        int ptr = i;
        map<char, int> mp;
        while (ptr < n)
        {
            mp[s[ptr]]++;
            ptr += k;
        }

        if (mp['0'] && mp['1'])
        {
            cout << "NO\n";
            return;
        }

        char c = '?';
        if (mp['0'])
        {
            c = '0';
        }
        else if (mp['1'])
        {
            c = '1';
        }

        ptr = i;
        while (ptr < n)
        {
            s[ptr] = c;
            ptr += k;
        }
    }
    // cerr << s << '\n';
    int c1 = count(s.begin(), s.begin() + k, '1');
    int c2 = count(s.begin(), s.begin() + k, '0');

    if (c1 > k / 2 || c2 > k / 2)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    return;
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
