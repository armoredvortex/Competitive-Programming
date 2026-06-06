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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> inDeg(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        inDeg[v]++;
    }

    vector<int> topo_order;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (inDeg[i] == 0)
        {
            st.push(i);
        }
    }

    while (!st.empty())
    {
        auto e = st.top();
        st.pop();
        topo_order.push_back(e);
        for (auto f : adj[e])
        {
            if (--inDeg[f] == 0)
            {
                st.push(f);
            }
        }
    }

    if (topo_order.size() != n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (auto e : topo_order)
        {
            cout << e + 1 << ' ';
        }
    }
}