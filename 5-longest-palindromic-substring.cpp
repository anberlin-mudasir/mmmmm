class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        vector<vector<bool>> iscyc(s.size(), vector<bool>(s.size(), false));
        
        int maxi=0, maxl = 1;
        for(int i=0; i<s.size(); i++){
            // odd size
            for(int r=1; i-r>=0 && i+r<s.size(); r++){
                if(s[i-r] != s[i+r]) break;
                else if(2*r+1>maxl){
                    maxl = 2*r+1;
                    maxi = i-r;
                }
            }
            // even
            for(int r=0; i-r>=0 && i+1 + r<s.size(); r++){
                if(s[i-r] != s[i+1+r]) break;
                else if(2*r+2>maxl){
                    maxl = 2*r+2;
                    maxi = i-r;
                }
            }
        }
        return s.substr(maxi, maxl);
    }
};
