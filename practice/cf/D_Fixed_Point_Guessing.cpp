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
    int n;
    cin >> n;

    int left = 1, right = n;
    int mid;

    while (left <= right)
    {
        set<int> swapped;

        mid = left + (right - left) / 2;
        cout << "? " << mid << ' ' << right << '\n';
        cout.flush();

        set<int> q;
        for (int i = mid; i <= right; i++)
        {
            int a;
            cin >> a;
            q.insert(a);
        }

        for (auto e : q)
        {
            if (e < mid || e > right)
            {
                swapped.insert(e);
            }
        }

        int extra = q.size() - swapped.size();

        if (extra == 1)
        {
            for (auto e : q)
            {
                if (swapped.find(e) == swapped.end())
                {
                    cout << "! " << e << '\n';
                    cout.flush();
                    return;
                }
            }
        }
        else if (extra % 2 == 0)
        {
            right = mid-1;
        }
        else
        {
            left = mid + 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}

// 1 2 3 4 5 6 7 8 9
// 5 4 8 2 1   6 3 9