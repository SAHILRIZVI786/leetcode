class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long absDividend = abs((long)dividend);
        long absDivisor = abs((long)divisor);
        
        long quotient = 0;
        
        while (absDividend >= absDivisor) {
            long tempDivisor = absDivisor;
            long multiple = 1;
            
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            absDividend -= tempDivisor;
    
            quotient += multiple;
        }
        
        
        return isNegative ? -quotient : quotient;
    }
};