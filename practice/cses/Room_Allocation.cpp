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
    ll n;
    cin >> n;

    multiset<vector<ll>> m;
    for (ll i = 0; i < n; i++)
    {
        vector<ll> v(3);
        cin >> v[0] >> v[1];
        v[2] = i;
        m.insert(v);
    }

    ll ct = 1;
    vll room(n, 0);
    auto it = m.begin();
    while (m.size())
    {
        vector<ll> t(3);
        t[0] = (*it)[1] + 1;
        room[(*it)[2]] = ct;
        // cerr << (*it)[0];
        // cerr << t << '\n';
        m.erase(it);

        it = m.lower_bound(t);
        if (it == m.end())
        {
            ct++;
            it = m.begin();
        }
    }

    cout << *max_element(room.begin(), room.end()) << '\n';
    for (auto e : room)
    {
        cout << e << ' ';
    }
}