#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, char>> freq(26);
    for (int i = 0; i < 26; ++i)
    {
        freq[i] = {0, 'a' + i};
    }
    for (char c : s)
    {
        freq[c - 'a'].first++;
    }

    sort(freq.rbegin(), freq.rend());

    int min_changes = 1e9;
    int best_k = -1;

    for (int k = 1; k <= 26; ++k)
    {
        if (n % k == 0)
        {
            int c = n / k;
            int kept = 0;

            for (int i = 0; i < k; ++i)
            {
                kept += min(freq[i].first, c);
            }

            int changes = n - kept;
            if (changes < min_changes)
            {
                min_changes = changes;
                best_k = k;
            }
        }
    }

    int c = n / best_k;
    vector<int> target_freq(26, 0);

    for (int i = 0; i < best_k; ++i)
    {
        target_freq[freq[i].second - 'a'] = c;
    }

    vector<int> current_kept(26, 0);
    string t = s;
    vector<int> replace_indices;

    for (int i = 0; i < n; ++i)
    {
        char ch = s[i];
        if (target_freq[ch - 'a'] > 0 && current_kept[ch - 'a'] < target_freq[ch - 'a'])
        {
            current_kept[ch - 'a']++;
        }
        else
        {
            replace_indices.push_back(i);
        }
    }

    int char_idx = 0;
    for (int idx : replace_indices)
    {
        while (char_idx < best_k && current_kept[freq[char_idx].second - 'a'] == c)
        {
            char_idx++;
        }

        char needed_char = freq[char_idx].second;
        t[idx] = needed_char;
        current_kept[needed_char - 'a']++;
    }

    cout << min_changes << '\n';
    cout << t << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}