#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

ll diff(map<ll, ll> &mp)
{
    if (mp.size() == 0)
    {
        return 0;
    }
    return (*mp.rbegin()).first - (*mp.begin()).first;
}

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    // cerr << v << '\n';
    ll left = 0, right = 0;
    ll mx = 0, ml, mr;
    map<ll, ll> mp;
    while (right < n)
    {
        mp[v[right]]++;
        // cerr << diff(mp) << '\n';
        while (diff(mp) > k)
        {
            // cerr << left << ' ' << right << '\n';
            if (--mp[v[left]] == 0)
            {
                mp.erase(v[left]);
            }
            left++;
        }
        if (right - left + 1 > mx)
        {
            mr = right;
            ml = left;
            mx = right - left + 1;
        }
        right++;
    }
    // cerr << ml << ' ' << mr;
    // cout << ans;
    vll v2;
    for (ll i = 0; i < n; i++)
    {
        if (i >= ml && i <= mr)
        {
            continue;
        }
        v2.push_back(v[i]);
    }

    if (v2.size() == 0)
    {
        cout << mx;
        return 0;
    }

    // cerr << v2 << '\n';
    ll left2 = 0, right2 = 0;
    ll mx2 = 0, ml2, mr2;
    map<ll, ll> mp2;
    while (right2 < v2.size())
    {
        mp2[v2[right2]]++;
        //     cerr << diff(mp2) << '\n';
        while (diff(mp2) > k)
        {
            //         // cerr << left << ' ' << right << '\n';
            if (--mp2[v2[left2]] == 0)
            {
                mp2.erase(v2[left2]);
            }
            left2++;
        }
        if (right2 - left2 + 1 > mx2)
        {
            mr2 = right2;
            ml2 = left2;
            mx2 = right2 - left2 + 1;
        }
        right2++;
    }

    cout << mx + mx2;
}