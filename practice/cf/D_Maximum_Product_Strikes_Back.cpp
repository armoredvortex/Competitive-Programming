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
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int max_twos = 0;
    int best_l = n, best_r = 0;

    auto count_twos = [&](int L, int R)
    {
        if (L > R)
            return 0;
        int count = 0;
        for (int k = L; k <= R; k++)
        {
            if (abs(a[k]) == 2)
                count++;
        }
        return count;
    };

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            continue;

        int j = i;
        int negs = 0;
        int first_neg = -1, last_neg = -1;

        while (j < n && a[j] != 0)
        {
            if (a[j] < 0)
            {
                negs++;
                if (first_neg == -1)
                    first_neg = j;
                last_neg = j;
            }
            j++;
        }

        if (negs % 2 == 0)
        {
            int twos = count_twos(i, j - 1);
            if (twos > max_twos)
            {
                max_twos = twos;
                best_l = i;
                best_r = n - j;
            }
        }
        else
        {
            int twos1 = count_twos(first_neg + 1, j - 1);
            if (twos1 > max_twos)
            {
                max_twos = twos1;
                best_l = first_neg + 1;
                best_r = n - j;
            }
            int twos2 = count_twos(i, last_neg - 1);
            if (twos2 > max_twos)
            {
                max_twos = twos2;
                best_l = i;
                best_r = n - last_neg;
            }
        }

        i = j - 1;
    }

    cout << best_l << ' ' << best_r << '\n';
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