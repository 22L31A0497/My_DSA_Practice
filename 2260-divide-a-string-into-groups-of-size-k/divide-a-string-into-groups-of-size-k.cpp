class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
      vector<string>ans;
      if(s.length()%k !=0){
        s.append(k-(s.length()%k),fill);
      }
      for(int i=0;i<s.length();i+=k){
        ans.push_back(s.substr(i,k));
      }
      return ans;
    }
};