#include <bits/stdc++.h>
using namespace std;

#define int long long int
double rec(int level, vector<double> &dp, int a, int b)
{
    if (level <= 0)
        return 0;
    if (dp[level] != -1)
        return dp[level];
    double ans = 1;
    if (a == 0)
    {
        for (int i = 1; i <= b; i++)
        {
            ans += (1.0 / (b - a + 1)) * (rec(level - i, dp, a, b));
        }
        ans /= (1.0 - (1.0 / (b - a + 1)));
        return dp[level] = ans;
    }
    for (int i = a; i <= b; i++)
    {
        ans += (1.0 / (b - a + 1)) * (rec(level - i, dp, a, b));
    }

    return dp[level] = ans;
}
int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;

    while (t--)
    {

        int n, a, b;
        cin >> n >> a >> b;
        vector<double> dp(n + 1, -1);
        dp[0] = 0;
        vector<double> prefix(n + 1, 0);
        prefix[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            double sum = 0;
            if (a == 0)
            {
                sum += (prefix[i - 1]) - prefix[max(0LL, i - b - 1)];
                dp[i] = 1 + (sum / (b - a + 1));
                dp[i] /= (1.0 - (1.0 / (b - a + 1)));
                prefix[i] = prefix[i - 1] + dp[i];
            }
            else
            {
                sum += (prefix[max(0LL, i - a)]) - prefix[max(0LL, i - b - 1)];

                dp[i] = 1 + (sum / (b - a + 1));
                prefix[i] = prefix[i - 1] + dp[i];
            }
        }
        cout << fixed << setprecision(10) << dp[n] << endl;
    }

    return 0;
}