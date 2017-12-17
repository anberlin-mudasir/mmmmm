class Solution {
public:
    int myAtoi(string str) {
        long long ret=0, sign=0, tmp;
        bool hasSign = false, allowBlank=true;

        for(char c : str){
            if(c == '-'){
                // what if multiple signs?
                if(hasSign) return 0;
                sign=1;
                hasSign = true;
                allowBlank = false;
            }
            // is there a '+' for possitive?
            else if( c== '+'){
                if(hasSign) return 0;
                hasSign = true;
                allowBlank = false;
            }
            // what if blank exists?
            else if(c == ' '){
                if(!allowBlank){
                    return sign ? -ret : ret;
                };
            }
            else if(c >= '0' && c<='9'){
                tmp = c - '0';
                ret *= 10;
                ret += tmp;
                allowBlank = false;
            }
            // what if illegal char exists?
            else return sign ? -ret : ret;
            // what if overflow?
            if(ret > 0x7fffffff && !sign){
                return 0x7fffffff;
            } 
            // or underflow?
            else if(ret > 0x80000000ll && sign){
                return (int)0x80000000;
            }
        }
        return sign ? -ret : ret;
    }
};

