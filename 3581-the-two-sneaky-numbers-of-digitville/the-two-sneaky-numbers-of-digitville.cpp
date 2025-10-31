//also there is a xor operation approach
//previously submitted that approach

// set based solution 
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        set<int>st;
        vector<int>ans;
        for(int num : nums){
            if(st.count(num)==1){
                ans.push_back(num);
            }
            else{
                st.insert(num);
            }
        }
        return ans;

        
    }
};

// map based approach 
// class Solution {
// public:
//     vector<int> getSneakyNumbers(vector<int>& nums) {
//         vector<int>ans;
//        map<int,int>mpp;
//        for(int num:nums){
//         mpp[num]++;
//        }
//        for(auto& it : mpp){
//         if(it.second>1){
//             ans.push_back(it.first);
//         }
//        }
//        return ans;

        
//     }
// };