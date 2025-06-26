class Solution {
public:
    int countGoodSubstrings(string s) {
        int count =0;
        int n = s.length();
        for(int i=0;i<=n-3;i++){
            set<int>st;
            for(int j=i;j<i+3;j++){
                st.insert(s[j]);
            }
            if(st.size()==3)count+=1;
        }
        return count;
        
    }
};