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

    vector<string> v;
    for (ll i = 0; i < 4; i++)
    {
        string s;
        getline(cin, s);
        v.push_back(s);
    }

    string ops;
    getline(cin, ops);

    ll ans = 0;

    ll l = 0;

    // cout << stoll("") << '\n';

    while (true)
    {
        char op = ops[l];
        ll r = l + 1;
        while (ops[r] == ' ')
        {
            r++;
        }

        string n1, n2, n3, n4;
        for (ll i = 0; i < 4; i++)
        {
            n1 += v[i][l];
        }
        if (r - l > 2)
        {
            for (ll i = 0; i < 4; i++)
            {
                if (v[i][l + 1] == ' ')
                {
                    continue;
                }
                n2 += v[i][l + 1];
            }
        }
        if (r - l > 3)
        {
            for (ll i = 0; i < 4; i++)
            {
                if (v[i][l + 2] == ' ')
                {
                    continue;
                }
                n3 += v[i][l + 2];
            }
        }
        if (r - l > 4)
        {
            for (ll i = 0; i < 4; i++)
            {
                if (v[i][l + 3] == ' ')
                {
                    continue;
                }
                n4 += v[i][l + 3];
            }
        }

        ll l1 = -1, l2 = -1, l3 = -1, l4 = -1;

        if (n1.size())
        {
            l1 = stoll(n1);
        }
        if (n2.size())
        {
            l2 = stoll(n2);
        }
        if (n3.size())
        {
            l3 = stoll(n3);
        }
        if (n4.size())
        {
            l4 = stoll(n4);
        }

        // auto l1 = stoll(n1), l2 = stoll(n2), l3 = stoll(n3), l4 = stoll(n4);

        cout << l1 << ' ' << l2 << ' ' << l3 << ' ' << l4 << '\n';
        // break;

        if (ops[l] == '+')
        {
            ll sub = 0;
            sub = (max(0ll, l1) + max(0ll, l2) + max(0ll, l3) + max(0ll, l4));
            cout << sub << '\n';
            ans += sub;
        }
        else
        {
            ll sub = 1;
            sub = (max(1ll, l1) * max(1ll, l2) * max(1ll, l3) * max(1ll, l4));
            cout << sub << '\n';
            ans += sub;
        }
        if (ops[r] == '=')
        {
            break;
        }
        l = r;
        r++;
    }

    cout << ans << '\n';

    return 0;
}