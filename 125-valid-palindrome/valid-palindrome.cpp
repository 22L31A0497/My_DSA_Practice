class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==1 && s[0] ==' ') return true;
        string m = "";
       
        for(auto i:s){
            if(isalnum(i)){
                m += tolower(i);
            }
        }
        string athu=m;
        reverse(m.begin(),m.end());
       return athu == m;
    }
};