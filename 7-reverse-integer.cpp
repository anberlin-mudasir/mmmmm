class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while(x){
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        // overflow, underflow
        if(ret > 0x7fffffff || ret < (long long)0 - 0x80000000) return 0;
        // what if 100000?
        return ret;
    }
};
