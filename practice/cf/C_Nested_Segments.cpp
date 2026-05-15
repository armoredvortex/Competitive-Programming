#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return b.second < a.second;
    }
    return a.first < b.first;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    map<pair<int, int>, vector<int>> idx;
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pairs[i].first >> pairs[i].second;
        idx[pairs[i]].push_back(i + 1);
    }

    sort(pairs.begin(), pairs.end(), comp);

    int mx = pairs[0].second;
    for (int i = 1; i < n; i++)
    {
        if (pairs[i].second <= mx)
        {
            if (pairs[i] == pairs[i - 1])
            {
                cout << idx[pairs[i]][0] << ' ' << idx[pairs[i]][1];
            }
            else
            {
                cout << idx[pairs[i]][0] << ' ' << idx[pairs[i - 1]][0];
            }
            // cout << idx[pairs[i]]
            //      << ' ' << idx[pairs[i - 1]] << '\n';
            return 0;
        }
        else
        {
            mx = max(mx, pairs[i].second);
        }
    }
    cout << "-1 -1";
}