class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1.0;

        long long nn = n;

        // Make exponent positive if negative
        if (nn < 0)
            nn = -nn;

        while (nn) {

            // If exponent is odd
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            }

            // If exponent is even
            else {
                x = x * x;
                nn = nn / 2;
            }
        }

        // Handle negative exponent
        if (n < 0)
            ans = 1.0 / ans;

        return ans;
    }
};