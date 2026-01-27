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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s;
    cin >> s;

    if (s.size() == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    map<char, ll> ct;
    map<pair<char, char>, ll> ct2;

    for (int i = 0; i < s.size(); i++)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            ct2[{c, s[i]}] += ct[c];
        }
        ct[s[i]]++;
    }

    ll ans = 0;
    for (auto e : ct2)
    {
        ans = max(ans, e.second);
    }

    for (auto e : ct)
    {
        ans = max(ans, e.second);
    }

    cout << ans << '\n';
    return 0;
}