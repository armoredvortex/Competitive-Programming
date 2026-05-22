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
    string s;
    cin >> s;

    map<char, int> mp;
    for (ll i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }

    vll factors;
    for (ll i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (n / i != i)
            {
                factors.push_back(n / i);
            }
        }
    }

    ll ans = INT_MAX;
    ll mine = -1;
    for (auto e : factors)
    {
        if (e <= 26)
        {
            if (abs(e - (ll)mp.size()) < ans)
            {
                ans = abs(e - (ll)mp.size());
                mine = e;
            }
        }
    }
    cout << ans << '\n';
    cerr << mine << '\n';

    ll e = n / mine;
    for (int i = 0; i < n; i++)
    {
        if(mp[s[i]] < e){
                        
        }
    }
    
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