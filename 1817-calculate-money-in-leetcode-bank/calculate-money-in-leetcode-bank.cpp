class Solution {
public:
    int triSum(int n) { 
        return (n * (n + 1)) >> 1;
    }

    int totalMoney(int days) {
        int nWeeks = days / 7;
        int rDays = days % 7;        
        int total = triSum(days);
        if (days <= 7) return total;
        
        return total - 42 * triSum(nWeeks - 1) - 6 * nWeeks * rDays;
    }
};
