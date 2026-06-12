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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
namespace __gnu_pbds
{
    typedef tree<int,
                 null_type,
                 less_equal<int>,
                 rb_tree_tag,
                 tree_order_statistics_node_update>
        ordered_set;
}
using namespace __gnu_pbds;

void Insert(ordered_set &s, int x)
{ // this function inserts one more occurrence of (x) into the set.

    s.insert(x);
}

bool Exist(ordered_set &s, int x)
{ // this function checks weather the value (x) exists in the set or not.

    if ((s.upper_bound(x)) == s.end())
    {
        return 0;
    }
    return ((*s.upper_bound(x)) == x);
}

void Erase(ordered_set &s, int x)
{ // this function erases one occurrence of the value (x).

    if (Exist(s, x))
    {
        s.erase(s.upper_bound(x));
    }
}

int FirstIdx(ordered_set &s, int x)
{ // this function returns the first index of the value (x)..(0 indexing).

    if (!Exist(s, x))
    {
        return -1;
    }
    return (s.order_of_key(x));
}

int Value(ordered_set &s, int idx)
{ // this function returns the value at the index (idx)..(0 indexing).

    return (*s.find_by_order(idx));
}

int LastIdx(ordered_set &s, int x)
{ // this function returns the last index of the value (x)..(0 indexing).

    if (!Exist(s, x))
    {
        return -1;
    }
    if (Value(s, (int)s.size() - 1) == x)
    {
        return (int)(s.size()) - 1;
    }
    return FirstIdx(s, *s.lower_bound(x)) - 1;
}

int Count(ordered_set &s, int x)
{ // this function returns the number of occurrences of the value (x).

    if (!Exist(s, x))
    {
        return 0;
    }
    return LastIdx(s, x) - FirstIdx(s, x) + 1;
}

void Clear(ordered_set &s)
{ // this function clears all the elements from the set.

    s.clear();
}

int Size(ordered_set &s)
{ // this function returns the size of the set.

    return (int)(s.size());
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ordered_set st;
    ll ans = 0;
    for (auto e : v)
    {
        Insert(st, e);
        ans += FirstIdx(st, e) + 1;
    }
    cout << ans << '\n';
}