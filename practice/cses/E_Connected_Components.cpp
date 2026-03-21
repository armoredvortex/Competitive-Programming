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

    set<pair<ll, ll>> st;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v)
        {
            swap(u, v);
        }

        st.insert({u, v});
    }

    set<ll> not_visited;
    for (ll i = 0; i < n; i++)
    {
        not_visited.insert(i);
    }

    vector<ll> components;
    for (ll i = 0; i < n; i++)
    {
        if (not_visited.find(i) == not_visited.end())
        {
            continue;
        }
        components.push_back(0);
        not_visited.erase(i);
        stack<ll> s;
        s.push(i);
        while (!s.empty())
        {
            auto e = s.top();
            s.pop();
            components[components.size() - 1]++;

            auto it = not_visited.begin();
            while (it != not_visited.end())
            {
                ll f = *it;
                if (st.find({min(e, f), max(e, f)}) == st.end())
                {
                    s.push(f);
                    it = not_visited.erase(it);
                }
                else
                {
                    it++;
                }
            }
            // for (auto f : not_visited)
            // {
            //     if (st.find({min(e, f), max(e, f)}) == st.end())
            //     {
            //         s.push(f);
            //         not_visited.erase(f);
            //     }
            // }
        }
    }
    // cerr << components;
    cout << components.size() << '\n';
    sort(components.begin(), components.end());
    for (auto e : components)
    {
        cout << e << ' ';
    }
}