class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if(strs.empty()){
        //     return "";
        // }
        // string result = "";
        // sort(strs.begin(),strs.end());
        // string first = strs[0];
        // string second = strs[strs.size()-1];

        // for(int i =0;i<first.length();i++){
        //     if(i>=first.length()||first[i]!=second[i]){
        //         break;
        //     }
        //     result += first[i];
        // }
        // return result;
        // 2nd time practice
      if(strs.empty()) return "";
      sort(strs.begin(),strs.end());
      string ans="";
      string f = strs[0];
      string l = strs[strs.size()-1];
      for(int i =0;i<f.length();i++){
        if(i>f.length() || f[i]!=l[i]){
            break;
        }
        ans += f[i];
      }
      return ans;
    }
};