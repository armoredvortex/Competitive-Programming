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
    // cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);

    vll v = {4, 8, 15, 16, 23, 42};
    map<ll, pair<ll, ll>> mp;
    for (ll i = 0; i < 6; i++)
    {
        for (ll j = i + 1; j < 6; j++)
        {
            mp[v[i] * v[j]] = {v[i], v[j]};
        }
    }

    vll ans(6);

    cout << "? 1 2\n";
    fflush(stdout);

    ll resp1;
    cin >> resp1;
    set<ll> st;
    st.insert(mp[resp1].first);
    st.insert(mp[resp1].second);

    cout << "? 2 3\n";
    fflush(stdout);
    cin >>
        resp1;
    if (st.find(mp[resp1].first) != st.end())
    {
        ans[1] = mp[resp1].first;
        st.erase(mp[resp1].first);
        ans[0] = *st.begin();
        ans[2] = mp[resp1].second;
    }
    else
    {
        ans[1] = mp[resp1].second;
        st.erase(mp[resp1].second);
        ans[0] = *st.begin();
        ans[2] = mp[resp1].first;
    }
    st.clear();

    cout << "? 4 5\n";
    fflush(stdout);

    cin >> resp1;
    st.insert(mp[resp1].first);
    st.insert(mp[resp1].second);

    cout << "? 5 6\n";
    fflush(stdout);
    cin >> resp1;
    if (st.find(mp[resp1].first) != st.end())
    {
        ans[4] = mp[resp1].first;
        st.erase(mp[resp1].first);
        ans[3] = *st.begin();
        ans[5] = mp[resp1].second;
    }
    else
    {
        ans[4] = mp[resp1].second;
        st.erase(mp[resp1].second);
        ans[3] = *st.begin();
        ans[5] = mp[resp1].first;
    }

    cout << "! ";
    for (auto e : ans)
    {
        cout << e << ' ';
    }
    cout << '\n';
    fflush(stdout);
}