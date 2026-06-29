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
    ll n, k;
    cin >> n >> k;

    int sum = 0;
    int psum = 0;

    int flag = 1;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int mask = 1 << i;
            if (sum + mask <= n)
            {
                sum += mask;
                psum++;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    cout << psum << '\n';
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