class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        // substr val:idx map
        unordered_map<char, int> mp;
        unordered_map<char, int>::iterator it;
        int ret = 1;
        // substr begin index
        int b = 0;
        // substr last index
        for(int l=0; l<s.size(); l++){
            it = mp.find(s[l]);
            if(it != mp.end()){
                while(b <= it->second){
                    mp.erase(s[b++]);
                }
            }
            mp.insert(pair<char, int>(s[l], l));
            ret = max(ret, l - b + 1);
        }
        return ret;
    }
};
