class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            bool left = (mid == 0) || (arr[mid] > arr[mid - 1]);
            bool right = (mid == n - 1) || (arr[mid] > arr[mid + 1]);

            if (left && right) {
                return mid; // Found peak
            }
            else if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
                low = mid + 1; // Search right side
            }
            else {
                high = mid - 1; // Search left side
            }
        }
        return -1;
    }
};
