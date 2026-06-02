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
    vll v(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    if (mp[0] == 0)
    {
        cout << 0 << ' ';
        for (int i = 1; i <= n; i++)
        {
            cout << -1 << ' ';
        }
        return;
    }
    priority_queue<ll> pq;
    ll cost = 0;
    cout << mp[0] << ' ';
    for (ll i = 1; i < mp[0]; i++)
    {
        pq.push(0);
    }
    int flag = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (!flag)
        {
            cout << -1 << ' ';
            continue;
        }
        if (!mp[i - 1])
        {
            if (!pq.size())
            {
                cout << -1 << ' ';
                flag = 0;
            }
            else
            {
                cost += i - 1 - pq.top();
                pq.pop();
                cout << mp[i] + cost << ' ';
            }
        }
        else
        {
            cout << mp[i] + cost << ' ';
        }
        for (int j = 1; j < mp[i]; j++)
        {
            pq.push(i);
        }
    }
    cout << '\n';
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