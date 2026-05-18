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

    int n;
    cin >> n;
    vll v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<int, int> mp;
    mp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        mp[v[i]] = 1 + mp[v[i] - 1];
    }

    int mx_val = 0;
    int mx_i = 0;
    for (auto e : mp)
    {
        if (e.second > mx_val)
        {
            mx_val = max(mx_val, e.second);
            mx_i = e.first;
        }
    }

    cout << mx_val << '\n';

    int start = mx_i - mx_val + 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == start)
        {
            cout << i + 1 << ' ';
            start++;
        }
    }
    cout << '\n';
}