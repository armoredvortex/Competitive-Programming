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
    string s;
    cin >> s;
    vll p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<string> cycles;
    vll visited(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        ll ptr = i;
        string sub;
        while (!visited[ptr])
        {
            visited[ptr] = 1;
            sub += s[ptr];
            ptr = p[ptr] - 1;
        }
        cycles.push_back(sub);
    }

    vll clens;
    for (auto e : cycles)
    {
        for (int k = 1; k <= e.size(); k++)
        {
            if (e.size() % k)
                continue;
            ll flag = 1;
            for (ll j = 0; j < k; j++)
            {
                char c = -1;
                for (int i = j; i < e.size(); i += k)
                {
                    if (c == -1)
                    {
                        c = e[i];
                    }
                    else
                    {
                        if (c != e[i])
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (!flag)
                    break;
            }
            if (flag)
            {
                clens.push_back(k);
                break;
            }
        }
    }
    // cerr << cycles << '\n';

    // cerr << clens << '\n';
    ll ans = 1;
    for (auto e : clens)
    {
        ans = lcm(ans, e);
    }
    cout << ans << '\n';
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