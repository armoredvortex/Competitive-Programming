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

	ll ans = 0;
	for (int i = 0; i < 200; i++)
	{
		string s, scpy;
		cin >> s;
		scpy = s;

		string subans;

		ll left = 0;
		for (int j = 0; j < 12; j++)
		{
			auto k = max_element(s.begin() + left, s.end() - 11 + j) - s.begin();
			left = k + 1;
			subans += s[k];
		}
		cout << subans << '\n';

		if (subans.size())
			ans += stoll(subans);
	}
	cout << ans << '\n';
}