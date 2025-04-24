class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int size=st.size();
        int count =0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>temp;
            for(int j=i;j<nums.size();j++){
                temp.insert(nums[j]);
                if(temp.size()==size){
                    count++;
                }
            }
        }
        return count;

    }
};