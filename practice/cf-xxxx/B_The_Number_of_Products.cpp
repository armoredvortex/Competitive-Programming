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

    ll n;
    cin >> n;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<ll> ind;
    ind.push_back(-1);
    for (ll i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            ind.push_back(i);
        }
    }
    ind.push_back(n);

    // cerr << ind << '\n';

    vector<ll> diff;
    for (int i = 0; i < ind.size() - 1; i++)
    {
        diff.push_back(ind[i + 1] - ind[i]);
    }
    // cerr << diff << '\n';

    if (*min_element(all(v)) > 0)
    {
        cout << 0 << ' ' << n * (n + 1) / 2 << '\n';
        return 0;
    }

    ll a = 0, b = 0;

    vector<ll> post(diff.size() + 1);
    post[diff.size()] = 0;
    post[diff.size() - 1] = diff.back();
    post[diff.size() - 2] = *(diff.end() - 2);

    n = diff.size();
    for (ll i = 2; i < diff.size(); i++)
    {
        post[n - i - 1] = post[n - i + 1] + diff[n - i - 1];
    }

    // cerr << diff << '\n';
    // cerr << post;
    for (int i = 0; i < diff.size(); i++)
    {
        b += (diff[i] * (diff[i] - 1)) / 2;
    }

    for (int i = 0; i < diff.size() - 1; i++)
    {
        a += diff[i] * post[i + 1];
        b += diff[i] * post[i + 2];
    }

    cout << a << ' ' << b << '\n';
}
