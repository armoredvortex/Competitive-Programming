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

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    set<int> done;
    vector<int> tbd;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] < n && done.find(v[i]) == done.end())
        {
            done.insert(v[i]);
        }
        else
        {
            tbd.push_back(v[i]);
        }
    }

    vector<int> donev(done.begin(), done.end());
    reverse(donev.begin(), donev.end());
    reverse(tbd.begin(), tbd.end());

    for (int i = 0; i < n; i++)
    {
        if (done.find(i) != done.end())
        {
            continue;
        }
        else
        {
            while (tbd.size() && tbd.back() < 2 * i + 1)
            {
                tbd.pop_back();
            }

            if (!tbd.size())
            {
                while (donev.size() && donev.back() < 2 * i + 1)
                {
                    donev.pop_back();
                }

                if (!donev.size())
                {
                    cout << i << '\n';
                    return;
                }
                else
                {
                    auto e = donev.back();
                    done.erase(done.find(e));
                    donev.pop_back();
                }
            }
            else
            {
                tbd.pop_back();
            }
        }
    }
    cout << n << "\n";
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