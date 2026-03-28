#include <bits/stdc++.h>

// #include "debugging.h"

typedef long long ll;

using namespace std;
const int MAXN = 10000005;

vector<int> spf(MAXN);

void sieve()
{
    for (int i = 1; i < MAXN; i++)
    {
        spf[i] = i;
    }

    for (int i = 4; i < MAXN; i += 2)
    {
        spf[i] = 2;
    }

    for (int i = 3; i * i < MAXN; i += 2)
    {

        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

map<int, int> getFactorization(int x)
{
    map<int, int> ret;
    while (x != 1)
    {
        ret[spf[x]]++;
        x = x / spf[x];
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    ll n;
    cin >> n;
    vector<long long> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<ll, ll> minf, minf2, fct;
    for (ll i = 0; i < n; i++)
    {
        map<int, int> factors = getFactorization(v[i]);
        for (auto e : factors)
        {
            fct[e.first]++;
            if (minf.find(e.first) == minf.end())
            {
                minf[e.first] = e.second;
            }
            else if (minf[e.first] >= e.second)
            {
                minf2[e.first] = minf[e.first];
                minf[e.first] = e.second;
            }
            else
            {
                if (minf2.find(e.first) == minf2.end())
                {
                    minf2[e.first] = e.second;
                }
                else if (minf2[e.first] >= e.second)
                {
                    minf2[e.first] = e.second;
                }
            }
        }
    }

    // cerr << fct << '\n';
    // cerr << minf << '\n'
    //      << minf2 << '\n';
    ll ans = 1;
    for (auto e : minf)
    {
        if (fct[e.first] == n)
        {
            ans *= pow(e.first, max(minf[e.first], minf2[e.first]));
        }
        else if (fct[e.first] == n - 1)
        {
            ans *= pow(e.first, minf[e.first]);
        }
    }
    cout << ans;

    return 0;
}