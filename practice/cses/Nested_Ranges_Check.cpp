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

    vector<vector<ll>> v(n, vector<ll>(3));
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end(), [](vector<ll> v1, vector<ll> v2) -> bool
         { 
            if(v1[1] == v2[1]){
                return v1[0] > v2[0];
            }
    return (v1[1] < v2[1]); });

    ll k = 0;
    vector<ll> ans2(n);
    for (ll i = 0; i < n; i++)
    {

        if (k >= v[i][0])
        {
            ans2[v[i][2]] = 1;
        }
        else
        {
            ans2[v[i][2]] = 0;
        }
        k = max(k, v[i][0]);
        // st2.insert(v[i][0]);
    }

    for (auto e : ans2)
    {
        cout << e << ' ';
    }
    cout << '\n';
    sort(v.begin(), v.end(), [](vector<ll> v1, vector<ll> v2) -> bool
         {
         if(v1[0] == v2[0]){
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0]; });
    // multiset<ll> st;
    ll k2 = 0;
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++)
    {
        if (v[i][1] <= k2)
        {
            ans[v[i][2]] = 1;
        }
        else
        {
            ans[v[i][2]] = 0;
        }
        // st.insert(v[i][1]);
        k2 = max(k2, v[i][1]);
    }
    for (auto e : ans)
    {
        cout << e << ' ';
    }
}