#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {  // Loop through each element
            int nuums = nums[i];  // Store the current element
            int count = 0;  // Initialize count to track occurrences

            for(int j = 0; j < nums.size(); j++) {  // Inner loop to compare with all elements
                if(nums[j] == nuums) {
                    count += 1;  // Increment count when a match is found
                }
            }

            if(count == 1) {  // If count is 1, return the number
                return nuums;
            }
        }
        return -1; // Default return in case no single number is found (shouldn't happen in valid inputs)
    }
};
