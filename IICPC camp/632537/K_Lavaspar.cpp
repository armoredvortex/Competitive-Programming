#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

bool areAnagrams(const string &a, const string &b)
{
    if (a.size() != b.size())
        return false;
    vector<int> freq(26, 0);
    for (char ch : a)
        freq[ch - 'A']++;
    for (char ch : b)
    {
        if (--freq[ch - 'A'] < 0)
            return false;
    }
    return true;
}

bool checkDirection(const vector<vector<char>> &grid,
                    int row, int col, int dr, int dc,
                    const string &word,
                    vector<vector<bool>> &mark)
{

    int len = word.size();
    string sub;

    for (int k = 0; k < len; ++k)
    {
        int r = row + dr * k, c = col + dc * k;
        if (r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size())
            return false;
        sub.push_back(grid[r][c]);
    }

    if (areAnagrams(sub, word))
    {
        for (int k = 0; k < len; ++k)
        {
            int r = row + dr * k, c = col + dc * k;
            mark[r][c] = true;
        }
        return true;
    }
    return false;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> grid[i][j];

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];

    vector<vector<vector<bool>>> found(n,
                                       vector<vector<bool>>(rows, vector<bool>(cols, false)));

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

    for (int idx = 0; idx < n; ++idx)
    {
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                for (auto [dr, dc] : directions)
                {
                    checkDirection(grid, r, c, dr, dc, words[idx], found[idx]);
                }
            }
        }
    }

    int overlapCount = 0;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            int count = 0;
            for (int idx = 0; idx < n; ++idx)
            {
                if (found[idx][r][c])
                    count++;
            }
            if (count > 1)
                overlapCount++;
        }
    }

    cout << overlapCount << endl;
    return 0;
}