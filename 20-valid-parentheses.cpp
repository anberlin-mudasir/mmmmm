class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        vector<char> mp(256, ' ');
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        for(char c: s){
            if(stk.empty() || mp[c] != ' '){
                stk.push(c);
            }
            else{
                char lhs = stk.top();
                if(mp[lhs] != c){
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
