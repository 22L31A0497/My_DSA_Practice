class Solution {
public:
    // int ad(vector<int>& a)
    // {
    //       int ma = INT_MIN;
    //     for(int i=0;i<a.size();i++)
    //     {
    //         if(a[i]>ma) ma = a[i];
    //     }
    //     return ma;  
    // }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> a;
    //     vector<int> b;
    //     for(int i=0;i<k;i++)
    //     {
    //     a.push_back(nums[i]);
    //     }
    //     int l = ad(a);
    //     b.push_back(l);
    //     for(int i=k;i<nums.size();i++){
    //          a.erase(a.begin());
    //          a.push_back(nums[i]);
    //          int q = ad(a);
    //          b.push_back(q);
    //     }
    //      return b;
    // }
    
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        vector<int>ans;
//        int i=0;
//        while(i<nums.size() && i<=nums.size()-k){
//         int j=i;
//         int maxi=nums[j];
//         while(j<k+i && j<nums.size()){
//          maxi = max(nums[j],maxi);
//          j++;
//          }
//          ans.push_back(maxi);
//          i++;
        
//        }
//        return ans;
//     }
    
};

