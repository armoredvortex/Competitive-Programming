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

    ll n, m;
    cin >> n >> m;
    set<int> done;
    vll v(n);
    queue<vector<ll>> q;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        done.insert(a);
        v[i] = a;
    }
    for (auto a : v)
    {
        if (done.find(a - 1) == done.end())
        {
            q.push({a - 1, -1, 1});
            done.insert(a - 1);
        }
        if (done.find(a + 1) == done.end())
        {
            q.push({a + 1, +1, 1});
            done.insert(a + 1);
        }
    }

    ll sum = 0;
    vll ans;
    for (int i = 0; i < m; i++)
    {
        auto e = q.front();
        q.pop();
        ans.push_back(e[0]);
        sum += e[2];
        if (e[1] == -1)
        {
            if (done.find(e[0] - 1) == done.end())
            {
                done.insert(e[0] - 1);
                q.push({e[0] - 1, -1, e[2] + 1});
            }
        }
        else
        {
            if (done.find(e[0] + 1) == done.end())
            {
                done.insert(e[0] + 1);
                q.push({e[0] + 1, +1, e[2] + 1});
            }
        }
    }
    cout << sum << '\n';
    for (auto e : ans)
    {
        cout << e << ' ';
    }
    return 0;
}