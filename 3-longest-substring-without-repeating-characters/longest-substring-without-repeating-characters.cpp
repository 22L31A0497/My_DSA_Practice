
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s.length()==0)return 0;
       int maxi=INT_MIN;
       int l=0;
        unordered_set < char > st;
       for(int r=0;r<s.length();r++){
         if(st.find(s[r])!=st.end()){
            while(l<r && st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
         }
         st.insert(s[r]);
         maxi=max(maxi,r-l+1);
       } 
       return maxi;
    }
};