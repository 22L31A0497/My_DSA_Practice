#define MAX(A, B) ((A) > (B) ? (A) : (B))
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());
        const int n = events.size();

        vector<int> start(n);

        vector<int> sufmax(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            start[i] = events[i][0];
            sufmax[i] = MAX(sufmax[i + 1],  events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int j = lower_bound(start.begin(), start.end(), events[i][1] + 1) - start.begin();
            int dp1 = events[i][2] + sufmax[j];
            ans = MAX(ans, dp1);
        }

        return ans;
    }
};