class Solution {
public:
    string reverseWords(string s) {
        string res;
        string word;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == ' '){
                if(word.size() != 0){
                    if(res.size() == 0){
                        res += word;
                    } else {
                        res += (' ' + word);
                    }
                word = "";
                }
            } else {
                word = s[i] + word;
            }
        }
        if(word.size() > 0 && res.size() != 0){
            res += ' ' + word;
        } else if(word.size() > 0) {
            res += word;
        }

        return res;

    }
};