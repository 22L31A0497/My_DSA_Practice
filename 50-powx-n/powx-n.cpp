class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;  // Base case: x^0 = 1
        
        long long N = n;  // Convert to long long to prevent overflow
        if (N < 0) {
            x = 1 / x;  // Convert negative exponent to positive
            N = -N;
        }

        double res = 1;
        while (N > 0) {
            if (N % 2 == 0) {  // Even power
                x = x * x;
                N = N / 2;
            } else {  // Odd power
                res = res * x;
                N = N - 1;
            }
        }
        return res;
    }
};