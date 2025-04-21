class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int minPrefixSum = 0, maxPrefixSum = 0;
        int currentSum = 0;

        for(const int& diff : differences) {
            currentSum += diff;
            minPrefixSum = min(minPrefixSum, currentSum);  // Track min prefix sum
            maxPrefixSum = max(maxPrefixSum, currentSum);  // Track max prefix sum

            // Early pruning if it's already out of bounds
            if (maxPrefixSum - minPrefixSum > upper - lower) {
                return 0;
            }
        }

        // Count the number of valid starting values
        return (upper - lower) - (maxPrefixSum - minPrefixSum) + 1;
    }
};
