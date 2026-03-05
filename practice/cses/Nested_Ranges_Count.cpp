#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define len(x) int((x).size())
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

// find_by_order, order_of_key: 0 indexed
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// allows duplicate values
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    vector<vector<ll>> v(n, vector<ll>(3));
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end(), [](const vector<ll> &v1, const vector<ll> &v2) -> bool
         { 
            if(v1[1] == v2[1]){
                return v1[0] > v2[0];
            }
            return (v1[1] < v2[1]); });

    ordered_multiset<ll> st2;
    vector<ll> ans2(n);
    for (ll i = 0; i < n; i++)
    {
        ans2[v[i][2]] = st2.size() - st2.order_of_key(v[i][0]);
        st2.insert(v[i][0]);
    }

    for (auto e : ans2)
    {
        cout << e << ' ';
    }
    cout << '\n';
    sort(v.begin(), v.end(), [](const vector<ll> &v1, const vector<ll> &v2) -> bool
         {
         if(v1[0] == v2[0]){
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0]; });

    ordered_multiset<ll> st;
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++)
    {
        ans[v[i][2]] = st.size() - st.order_of_key(v[i][1]);
        st.insert(v[i][1]);
    }
    for (auto e : ans)
    {
        cout << e << ' ';
    }
}