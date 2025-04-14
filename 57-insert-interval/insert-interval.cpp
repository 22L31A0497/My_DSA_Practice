class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;  // Final answer

        int i = 0;
        int n = intervals.size();

        // Step 1: Add all intervals that come BEFORE the newInterval (no overlap)
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        // Example:
        // intervals = [[1,3], [6,9]], newInterval = [2,5]
        // Check: intervals[0][1] = 3 < 2 ? ❌ → Stop here
        // So, result = []

        // Step 2: Merge all OVERLAPPING intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            // Merge the current interval into newInterval
            newInterval[0] = min(newInterval[0], intervals[i][0]);  // left bound
            newInterval[1] = max(newInterval[1], intervals[i][1]);  // right bound
            i++;
        }
        // In our example:
        // intervals[0] = [1,3] → [1 <= 5] ✅ → merge → newInterval = [1,5]
        // intervals[1] = [6,9] → [6 <= 5] ❌ → stop

        result.push_back(newInterval);  // push the merged newInterval
        // result = [[1,5]]

        // Step 3: Add remaining intervals AFTER newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        // Here, i = 1, so push [6,9]
        // result = [[1,5], [6,9]]

        return result;
    }
};
