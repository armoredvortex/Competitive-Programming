class Solution {
public:
    int beautySum(string s) {
        vector<vector<int>> freq(s.size()+1, vector<int>(26, 0));

        for(int i=0; i<s.size(); i++){
            for(int j=0; j<26; j++){
                freq[i+1][j] = freq[i][j];
            }
            freq[i+1][s[i] - 'a']++;
        }

        int ans = 0;

        for(auto e: freq){
            for(auto f: e){
                cout << f << ' ';
            }
            cout << '\n';
        }
        for(int i=0; i<s.size(); i++){
            for(int j=i+1; j<s.size()+1; j++){
                int mx, mn;
                for(int k=0; k<26; k++){
                    if(freq[j][k] - freq[i][k] != 0){
                        mx = freq[j][k] - freq[i][k];
                        mn = freq[j][k] - freq[i][k];
                        break;
                    }
                }

                for(int k=0; k<26; k++){
                    if(freq[j][k] - freq[i][k] != 0){
                    mx = max(mx, freq[j][k] - freq[i][k]);
                    mn = min(mn, freq[j][k] - freq[i][k]);
                    }
                }

                ans += (mx - mn);
            }
        }

        return ans;

    }
};