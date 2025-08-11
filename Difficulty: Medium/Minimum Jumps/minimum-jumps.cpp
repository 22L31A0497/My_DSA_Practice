#include <vector>
#include <algorithm> // For std::max

class Solution {
public:
    int minJumps(std::vector<int>& arr) {
        int n = arr.size();

        // If there's only one element, we are already at the end. 0 jumps needed.
        if (n <= 1) {
            return 0;
        }

        // If the first element is 0, we can't move anywhere.
        if (arr[0] == 0) {
            return -1;
        }

        // --- Greedy Approach Variables ---
        // The farthest point we can get to in total.
        int max_reach = arr[0]; 
        // The number of steps we have left in our current jump.
        int steps = arr[0];
        // The number of jumps taken so far. We start at the 1st jump from index 0.
        int jumps = 1;

        // Start iterating from the second element.
        for (int i = 1; i < n; i++) {
            // If we have reached the end of the array, return the number of jumps.
            if (i == n - 1) {
                return jumps;
            }

            // Look ahead: update the farthest we can reach from our current position.
            max_reach = std::max(max_reach, i + arr[i]);

            // We used one step to get to the current index 'i'.
            steps--;

            // If we have run out of steps for the current jump...
            if (steps == 0) {
                // ...we must take another jump.
                jumps++;

                // If our current position 'i' is beyond the farthest we could ever reach,
                // it means we are stuck and can't move forward.
                if (i >= max_reach) {
                    return -1;
                }

                // "Refuel" our steps for the next jump.
                // The new number of steps is the distance from our current position 'i'
                // to the new farthest reachable point.
                steps = max_reach - i;
            }
        }
        
        // This part should not be reached if the input is valid,
        // but it's good practice for completeness.
        return -1; 
    }
};