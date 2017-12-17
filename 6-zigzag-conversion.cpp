class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0) return "";
        if(numRows == 1) return s;
        
        int groupSize = 2 * numRows - 2;
        
        // get columns
        int numCols = s.size()/groupSize + (s.size()%groupSize ? 1 : 0);
        string ret="";
        
        for(int i=0; i<numCols; i++){
            ret += s[i*groupSize];
        }
        for(int i=1; i<numRows-1; i++){
            for(int j=0; j<numCols; j++){
                if(j*groupSize + i < s.size())
                    ret += s[j*groupSize + i];
                if((j+1)*groupSize-i < s.size())
                    ret += s[(j+1)*groupSize-i];
            }
        }
        for(int i=0; i<numCols; i++){
            if(numRows-1 + i*groupSize < s.size())
                ret += s[numRows-1 + i*groupSize];
        }
        return ret;
    }
};
