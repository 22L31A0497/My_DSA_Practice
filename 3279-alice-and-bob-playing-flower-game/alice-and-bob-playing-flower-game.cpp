class Solution {
public:
    long long flowerGame(int n, int m) {
         long long x_even = n / 2;
        long long x_odd  = (n + 1) / 2;
        long long y_even = m / 2;
        long long y_odd  = (m + 1) / 2;
        return x_even * y_odd + x_odd * y_even;
    }
};