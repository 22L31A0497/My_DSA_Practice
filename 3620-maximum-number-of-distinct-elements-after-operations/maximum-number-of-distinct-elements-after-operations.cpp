
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& arr, int diff) {
        sort(arr.begin(), arr.end());
        set<int> uniqueValues;
        int last = INT_MIN;

        for (int value : arr) {
            int newPos = max(last + 1, value - diff);
            if (newPos <= value + diff) {
                uniqueValues.insert(newPos);
                last = newPos;
            }
        }

        return uniqueValues.size();
    }
};