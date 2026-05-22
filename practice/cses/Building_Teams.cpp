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

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> colors(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (colors[i] != -1)
        {
            continue;
        }

        stack<int> st;
        st.push(i);
        colors[i] = 1;
        while (!st.empty())
        {
            auto e = st.top();
            st.pop();

            for (auto f : adj[e])
            {
                if (colors[f] == -1)
                {
                    st.push(f);
                    if (colors[e] == 1)
                    {
                        colors[f] = 2;
                    }
                    else if (colors[e] == 2)
                    {
                        colors[f] = 1;
                    }
                }
                else if (colors[e] == colors[f])
                {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }
    for (auto e : colors)
    {
        cout << e << ' ';
    }
}