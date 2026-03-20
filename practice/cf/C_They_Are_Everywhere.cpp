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

bool containsAll(set<char> &st, map<char, ll> &mp)
{
    for (auto e : st)
    {
        if (mp[e] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    set<char> uniq;
    for (auto e : s)
    {
        uniq.insert(e);
    }

    ll ans = LONG_LONG_MAX;
    map<char, ll> mp;
    ll left = 0, right = 0;
    while (right < n)
    {
        mp[s[right]]++;

        while (containsAll(uniq, mp))
        {
            ans = min(ans, right - left + 1);
            mp[s[left]]--;
            left++;
        }
        right++;
    }
    cout << ans;
}