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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    string s;
    cin >> s;

    string s_new;
    vector<int> v;

    for (int i = 0; i < s.size(); i++)
    {
        int a;
        cin >> a;
        if (s[i] == 'h' || s[i] == 'a' || s[i] == 'r' || s[i] == 'd')
        {
            s_new += s[i];
            v.push_back(a);
        }
    }

    cerr << s_new << '\n'
         << v;
}