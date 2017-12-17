class Solution {
public:
    bool isPalindrome(int x) {
        // what if x is negative?
        if(x<0) return false;
        long long high=1, low=1;
        while(x/high/10) high*=10;
        for(; low<high; low*=10, high/=10){
            int h = (x/high)%10;
            int l = (x/low)%10;
            if(h!=l) return false;
        }
        return true;
    }
};
