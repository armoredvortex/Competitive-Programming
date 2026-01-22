class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<int> indx(s.size());
        int ct = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                indx[i] = ct;
                ct++;
            } else {
                indx[i] = (ct-1);
                ct--;
            }
        }

        string res;
        for(int i=0; i<s.size(); i++){
            if(indx[i] != 0){
                res += s[i];
            }
        }

        return res;
    }
};