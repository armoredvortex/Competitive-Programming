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
    set<ll> s;
    for (ll i = 1; i <= n; i++)
    {
        s.insert(i);
    }

    auto it = ++s.begin();
    while (s.size() > 1)
    {
        cout << *it << ' ';
        it = s.erase(it);
        if (it == s.end())
        {
            it = ++s.begin();
        }
        else if (it == --s.end())
        {
            it = s.begin();
        }
        else
        {
            it++;
        }
    }
    cout << *s.begin() << ' ';
    // it = s.erase(it);
    // if (it == s.end())
    // {
    //     it = s.begin();
    // }
    // cout << *it << '\n';
}