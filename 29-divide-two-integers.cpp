class Solution {
public:
    int divide(int dividend, int divisor) {
        // overflow: divisor = 0
        if(divisor == 0) return dividend > 0 ? INT_MAX : INT_MIN;
        long long a = dividend, b = divisor;
        if(a<0) a = -a;
        if(b<0) b = -b;
        
        // overflow: divident=-2147483648, divisor=-1
        long long factor = 1;
        while(b <= a){
            b<<=1;
            factor<<=1;
        }
        b>>=1;
        factor>>=1;
        
        long long result = 0;
        for(;factor;factor>>=1, b>>=1){
            if(a>=b){
                a-=b;
                result += factor;
            }
        }
        if(dividend>0 && divisor<0 || dividend<0 && divisor>0){
            result = -result;
        } 
        // overflow: result = 2147483648 > INT_MAX
        if(result > INT_MAX) return INT_MAX;
        else if(result < INT_MIN) return INT_MIN;
        return result;
    }
};