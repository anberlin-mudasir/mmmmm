class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        int end = 0;
        while(true){
            if(end >= strs[0].size()) break;
            
            // break parent loop
            bool match = true;
            for(int i=1; i<strs.size(); i++){
                if(end >= strs[i].size() || strs[i][end] != strs[0][end]){
                    match = false;
                    break;
                }
            }
            if(!match) break;
            end++;
        }
        
        return strs[0].substr(0, end);
    }
};
