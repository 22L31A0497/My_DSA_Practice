class Solution {
    public:
      int lengthOfLongestSubstring(string s) {
          int max_len = 0;
              int len = s.size();
                  int start = 0;
                      map<char, int> m;

                          for(int end = 0; end < len; end++) {
                                if (m.find(s[end]) != m.end() && m[s[end]] >= start) {
                                        start = m[s[end]] + 1;
                                              }
                                                    m[s[end]] = end;
                                                          max_len = max(max_len, end - start + 1);
                                                              }
                                                                  
                                                                      return max_len;
                                                                          }
                                                                          };
