#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define endl '\n'

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    int sum = 0;
    if (a[0] != 0)
    {
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
    }
    else
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                count++;
            }
            else
            {
                sum += a[i];
            }
        }
        sum += count;
    }
    cout << sum << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}