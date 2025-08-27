class Solution {
public:
    set<long long> st;
    // bool flag=false;
    void helper(vector<int> &nums,vector<int> &temp,vector<vector<int>> &sol,int idx){
        if(idx>=nums.size()){
            long long  key=0;
            for(int i=0;i<temp.size();i++){
                key=key|(((long long)(temp[i]+21))<<(5*i));
                // cout<<key;
            }
            auto it=st.find(key);
            if(it==st.end()){
                st.insert(key);
                sol.emplace_back(temp);
            }
            return;
        }
        temp.emplace_back(nums[idx]);
        helper(nums,temp,sol,idx+1);
        temp.pop_back();
        helper(nums,temp,sol,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> sol;
        helper(nums,temp,sol,0);
        return sol;
    }
};
