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

    vector<ll> seq = {1};
    vector<ll> known(2 * n, -1);
    for (ll i = 2; i <= 2 * n; i++)
    {
        cout << "? " << seq.size() + 1 << ' ';
        for (auto e : seq)
        {
            cout << e << ' ';
        }
        cout << i << '\n';
        cout.flush();
        ll x;
        cin >> x;
        if (x != 0)
        {
            known[i - 1] = x;
        }
        else
        {
            seq.push_back(i);
        }
    }

    // cerr << known << '\n';

    vll seq2;
    for (ll i = 0; i < 2 * n; i++)
    {
        if (known[i] != -1)
        {
            seq2.push_back(i + 1);
        }
    }

    for (ll i = 1; i <= 2 * n; i++)
    {
        if (known[i - 1] != -1)
            continue;

        cout << "? " << seq2.size() + 1 << ' ';
        for (auto e : seq2)
        {
            cout << e << ' ';
        }
        cout << i << ' ';
        cout << '\n';
        cout.flush();
        ll x;
        cin >> x;
        if (x != 0)
        {
            known[i - 1] = x;
        }
    }

    cout << "! ";
    for (auto e : known)
    {
        cout << e << ' ';
    }
    cout << '\n';
    cout.flush();
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