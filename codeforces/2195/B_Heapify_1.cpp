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

    vll v(n), vc(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        vc[i] = v[i];
    }

    if (n == 1 || n == 2)
    {
        cout << "YES\n";
        return;
    }
    sort(vc.begin(), vc.end());

    vector<vector<int>> grp, grpc;

    vector<int> visited(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        vector<int> subg;
        vector<int> subgc;
        ll j = i + 1;
        while (j <= n)
        {
            visited[j - 1] = 1;
            subgc.push_back(vc[j - 1]);
            subg.push_back(v[j - 1]);
            j = j * 2;
        }
        grp.push_back(subg);
        grpc.push_back(subgc);
    }

    // cerr << grp << '\n'
    //      << grpc << '\n';
    for (ll i = 0; i < grp.size(); i++)
    {
        sort(grp[i].begin(), grp[i].end());
        sort(grpc[i].begin(), grpc[i].end());

        for (int j = 0; j < grp[i].size(); j++)
        {
            if (grp[i][j] != grpc[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    return;
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