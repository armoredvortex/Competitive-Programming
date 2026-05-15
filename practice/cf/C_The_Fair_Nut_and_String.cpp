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

const int MOD = 1e9 + 7;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s;
    cin >> s;

    vector<vector<int>> v;
    vector<int> sub;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            sub.push_back(i);
        }
        if (s[i] == 'b')
        {
            if (sub.size())
            {
                v.push_back(sub);
            }
            sub.clear();
        }
    }
    if (sub.size())
    {
        v.push_back(sub);
    }

    long long ans = 1;
    for (int i = 0; i < v.size(); i++)
    {
        ans = (ans * (v[i].size() + 1)) % MOD;
    }

    cout << ans - 1;
}