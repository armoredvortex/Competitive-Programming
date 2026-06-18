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

    ll n, m, q;
    cin >> n >> m >> q;
    vll va(n), vb(m);
    ll accA = 0,
       accB = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> va[i];
        accA += va[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> vb[i];
        accB += vb[i];
    }

    unordered_set<ll> avals, bvals;
    for (ll i = 0; i < n; i++)
    {
        avals.insert(accA - va[i]);
    }
    for (ll i = 0; i < m; i++)
    {
        bvals.insert(accB - vb[i]);
    }
    // cerr << avals << '\n'
    //      << bvals << '\n';
    while (q--)
    {
        ll qi;
        cin >> qi;
        if (qi >= 0)
        {
            ll flag = 1;
            for (ll i = 1; i <= sqrt(qi); i++)
            {
                if (qi % i == 0)
                {
                    if (avals.find(i) != avals.end() && bvals.find(qi / i) != bvals.end() ||
                        avals.find(-1 * i) != avals.end() && bvals.find(-1 * qi / i) != bvals.end() ||
                        avals.find(qi / i) != avals.end() && bvals.find(i) != bvals.end() ||
                        avals.find(-1 * qi / i) != avals.end() && bvals.find(-1 * i) != bvals.end())
                    {
                        cout << "YES\n";
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                cout << "NO\n";
            }
        }
        else
        {
            qi = abs(qi);
            ll flag = 1;
            for (ll i = 1; i <= sqrt(qi); i++)
            {
                if (qi % i == 0)
                {
                    if (avals.find(i) != avals.end() && bvals.find(-1 * qi / i) != bvals.end() ||
                        avals.find(-1 * i) != avals.end() && bvals.find(qi / i) != bvals.end() ||
                        avals.find(qi / i) != avals.end() && bvals.find(-1 * i) != bvals.end() ||
                        avals.find(-1 * qi / i) != avals.end() && bvals.find(i) != bvals.end())
                    {
                        cout << "YES\n";
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                cout << "NO\n";
            }
        }
    }
}