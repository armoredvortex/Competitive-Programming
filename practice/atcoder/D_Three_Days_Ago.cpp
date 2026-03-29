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

    vll states(s.size() + 1);
    states[0] = 0;
    ll st = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        st ^= (1 << (s[i] - '0'));
        states[i + 1] = st;
    }

    ll ans = 0;
    map<ll, ll> mp;
    for (ll i = 0; i < states.size(); i++)
    {
        ans += mp[states[i]];
        mp[states[i]]++;
    }
    cout << ans;

    // cerr << states;
}