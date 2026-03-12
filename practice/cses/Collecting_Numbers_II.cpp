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

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vll pos(n + 2);
    pos[0] = -1;
    pos[n + 1] = n;
    for (ll i = 0; i < n; i++)
    {
        pos[v[i]] = i;
    }

    ll init = 1;
    ll left = pos[1];
    while (true)
    {
        if (v[left] == n)
        {
            break;
        }
        ll next = pos[v[left] + 1];
        if (next < left)
        {
            init++;
        }
        left = next;
    }
    // cerr << init;

    for (ll k = 0; k < m; k++)
    {
        ll i, j;
        cin >> i >> j;
        if (i > j)
        {
            swap(i, j);
        }
        i--;
        j--;

        ll x = v[i], y = v[j];
        if (pos[x + 1] > i && pos[x + 1] < j)
            init++;
        if (pos[x - 1] > i && pos[x - 1] < j)
            init--;

        if (pos[y + 1] > i && pos[y + 1] < j)
            init--;
        if (pos[y - 1] > i && pos[y - 1] < j)
            init++;

        if (x == (y - 1))
            init++;
        if (y == (x - 1))
            init--;

        swap(v[i], v[j]);
        swap(pos[v[i]], pos[v[j]]);
        cout << init << '\n';
    }
}