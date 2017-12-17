class Solution {
public:
    int strStr(string haystack, string needle) {
        // !important: convert unsinged to signed
        for(int i=0; i<=(int)haystack.size()-(int)needle.size(); i++){
            bool matched = true;
            for(int j=0;j<needle.size();j++){
                if(needle[j]!=haystack[i+j]){
                    matched = false;
                    break;
                }
            }
            if(matched) return i;
        }
        return -1;
    }
};