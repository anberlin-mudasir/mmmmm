class Solution {
public:
    vector<string> calc(const vector<string>& mp, const string& digits){
        if(digits.size()==0) return {};
        if(digits.size()==1) {
            vector<string> ret;
            for(char c: mp[digits[0]-'0']){
                ret.push_back(string(1, c));
            }
            return ret;
        }
        vector<string> suffixes = calc(mp, digits.substr(1));
        vector<string> ret;
        for(char c: mp[digits[0]-'0']){
            for(string& suffix: suffixes){
                ret.push_back(c + suffix);
            }
        }
        return ret;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> letterMap = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return calc(letterMap, digits);
    }
};