#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

void printv(vector<ll> &v)
{
    for (auto &e : v)
    {
        cout << e << ' ';
    }
    cout << endl;
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll act = count(all(s), 'a'), bct = count(all(s), 'b');

    vector<ll> apos, bpos;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            apos.push_back(i);
        }
        else
        {
            bpos.push_back(i);
        }
    }

    vector<ll> apospre, bpospre;
    apospre.push_back(0);
    for (int i = 0; i < apos.size(); i++)
    {
        apospre.push_back(apospre.back() + apos[i]);
    }

    bpospre.push_back(0);
    for (int i = 0; i < bpos.size(); i++)
    {
        bpospre.push_back(bpospre.back() + bpos[i]);
    }

    ll minsa, minsb;
    {
        ll mins = -1;
        for (int i = 0; i < n - act + 1; i++)
        {
            ll start = i;
            ll end = i + act;

            auto abeg = lower_bound(apos.begin(), apos.end(), start);
            auto aend = lower_bound(apos.begin(), apos.end(), end);

            // ll s1 = accumulate(apos.begin(), abeg, 0ll);
            // ll s2 = accumulate(aend, apos.end(), 0ll);

            ll s1 = apospre[abeg - apos.begin()] - apospre[0];
            ll s2 = apospre[apos.end() - apos.begin()] - apospre[aend - apos.begin()];

            auto bbeg = lower_bound(bpos.begin(), bpos.end(), start);
            auto bend = lower_bound(bpos.begin(), bpos.end(), end);

            // ll as1 = accumulate(bbeg, bbeg + (abeg - apos.begin()), 0ll);
            // ll as2 = accumulate(bbeg + (abeg - apos.begin()), bend, 0ll);

            ll as1 = bpospre[(bbeg + (abeg - apos.begin())) - bpos.begin()] - bpospre[bbeg - bpos.begin()];
            ll as2 = bpospre[bend - bpos.begin()] - bpospre[bbeg + (abeg - apos.begin()) - bpos.begin()];

            // cerr << s2 - s1 + as1 - as2 << endl;
            ll sss = s2 - s1 + as1 - as2;
            if (mins == -1)
            {
                mins = sss;
            }
            else
            {
                if (sss < mins)
                {
                    mins = sss;
                }
            }
        }
        minsa = mins;
    }

    {
        ll mins = -1;
        for (int i = 0; i < n - bct + 1; i++)
        {
            ll start = i;
            ll end = i + bct;

            auto bbeg = lower_bound(bpos.begin(), bpos.end(), start);
            auto bend = lower_bound(bpos.begin(), bpos.end(), end);

            // ll s1 = accumulate(bpos.begin(), bbeg, 0ll);
            // ll s2 = accumulate(bend, bpos.end(), 0ll);

            ll s1 = bpospre[bbeg - bpos.begin()] - bpospre[0];
            ll s2 = bpospre[bpos.end() - bpos.begin()] - bpospre[bend - bpos.begin()];

            auto abeg = lower_bound(apos.begin(), apos.end(), start);
            auto aend = lower_bound(apos.begin(), apos.end(), end);

            // ll bs1 = accumulate(abeg, abeg + (bbeg - bpos.begin()), 0ll);
            // ll bs2 = accumulate(abeg + (bbeg - bpos.begin()), aend, 0ll);

            ll bs1 = apospre[abeg + (bbeg - bpos.begin()) - apos.begin()] - apospre[abeg - apos.begin()];
            ll bs2 = apospre[aend - apos.begin()] - apospre[abeg + (bbeg - bpos.begin()) - apos.begin()];

            // cerr << s2 - s1 + as1 - as2 << endl;
            ll sss = s2 - s1 + bs1 - bs2;
            if (mins == -1)
            {
                mins = sss;
            }
            else
            {
                if (sss < mins)
                {
                    mins = sss;
                }
            }
        }
        minsb = mins;
    }

    cout << min(minsa, minsb) << endl;
    // cout << mins << endl;

    // printv(apos);
    // printv(bpos);
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