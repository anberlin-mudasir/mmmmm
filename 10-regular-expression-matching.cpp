class Solution {
public:
    bool isMatch(string s, string p) {
        // assume pattern not empty
        if(p.size() == 0){
            return s.size() == 0;
        }
        
        int i = p.size();
        char c = p[--i];
        bool repeat = false;
        if(c == '*'){
            // invalid regex
            if(p.size()==1) throw 1;
            
            repeat = true;
            c = p[--i];
        }
        p = p.substr(0, i);
        
        if(c == '.'){
            if(repeat){
                for(int j=0;j<=s.size();j++){
                    if(isMatch(s.substr(0, j), p)) return true;
                }
            }
            else{
                return 
                    // fail when s empty
                    s.size() 
                    // fail when prefix not match
                    && isMatch(s.substr(0, s.size()-1), p);
            }
        }
        else{
            if(repeat){
                // max match index
                int j=s.size();
                // min match index
                while(j-1>=0 && s[j-1] == c) j--;
                // possible matches: [j, s.size()), [s.size(), s.size()) 
                for(int k=j; k<=s.size(); k++){
                    if(isMatch(s.substr(0, k), p)) return true;
                }
            }
            else{
                return 
                    // fail when s empty
                    s.size() 
                    // fail when not match
                    && s.back() == c 
                    // fail when prefix not match
                    && isMatch(s.substr(0, s.size()-1), p);
            }
        }
        return false;
    }
};
