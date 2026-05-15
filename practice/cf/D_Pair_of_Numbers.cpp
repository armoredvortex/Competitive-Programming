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

const int MAXN = 1e6;
const int K = 25;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int lg[MAXN + 1];
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i / 2] + 1;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int st[K + 1][MAXN];

    std::copy(v.begin(), v.end(), st[0]);

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

    //  int i = lg[R - L + 1];
    //  int minimum = min(st[i][L], st[i][R - (1 << i) + 1]);

    int lft = 0, right = n - 1;
    int mid, ans = -1;

    while (lft <= right)
    {
        mid = lft + (right - lft) / 2;
        for (int k = 0; k + mid < n; k++)
        {
            int L = k, R = k + mid - 1;
            int i = lg[R - L + 1];
            int minimum = gcd(st[i][L], st[i][R - (1 << i) + 1]);
        }
    }
}