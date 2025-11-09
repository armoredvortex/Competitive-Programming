#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<long double> a(n);
        for (auto &i : a)
        {
            cin >> i;
        }

        if (k == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << fixed << setprecision(8) << a[i] << " ";
            }
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            long double ans = 0;
            double r = (double)k / n;
            int x = i;
            // cout<<x<<" Starting index"<<endl;
            int c = n - 1;
            for (int i = 0; i < n - k + 1; i++)
            {
                // cout<<a[x]<<"value of ax
                // "<<endl;

                ans += r * a[x];
                x = (x - 1 + n) % n;

                // cout<<ans<<"temp"<<endl;
                r = r * (c - (k - 1)) / c;
                c = c - 1;
            }

            cout << fixed << setprecision(8) << ans << " ";
        }
    }

    return 0;
}