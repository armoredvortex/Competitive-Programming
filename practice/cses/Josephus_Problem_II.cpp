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

#include <bits/extc++.h>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
void example()
{
    Tree<int> t, t2;
    t.insert(8);
    auto it = t.insert(10).first;
    assert(it == t.lower_bound(9));
    assert(t.order_of_key(10) == 1);
    assert(t.order_of_key(11) == 2);
    assert(*t.find_by_order(0) == 8);
    t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;
    Tree<int> s;
    for (ll i = 0; i < n; i++)
    {
        s.insert(i + 1);
    }

    if (k == 0)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << i + 1 << ' ';
        }
        return 0;
    }
    auto it = s.find_by_order(k % n);
    while (s.size() > 1)
    {
        cout << *it << ' ';

        ll key = *it;
        s.erase(it);
        it = s.find_by_order((s.order_of_key(key) + k - 1) % s.size());
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
}