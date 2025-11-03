#include <string>
#include <vector>
#include <algorithm> // For std::min and std::max

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int totalTime = 0;

        // Iterate from the second balloon (index 1)
        for (int i = 1; i < n; ++i) {
            
            // Check if the current balloon has the same color as the previous one
            if (colors[i] == colors[i-1]) {
                
                // We have a conflict and must remove one balloon.
                // To minimize the total time, we remove the one with the *smaller* removal time.
                totalTime += min(neededTime[i], neededTime[i-1]);
                
                // For the *next* comparison (at i+1), the "previous" balloon
                // will be the one we *kept* (the one with the larger time).
                // We update the time at the current index 'i' to reflect this,
                // ensuring we carry forward the cost of the balloon we kept.
                neededTime[i] = max(neededTime[i], neededTime[i-1]);
            }
        }
        
        // The total accumulated time is our minimum time.
        return totalTime;
    }
};