
class Solution {
  public:
    vector<int> common_digits(vector<int> nums) {
        set<int>st;
        for(int num:nums){
            while(num>0){
                st.insert(num%10);
                num = num/10;
                
            }
            
        }
        return vector<int>(st.begin(),st.end());
    }
};