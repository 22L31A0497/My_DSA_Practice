// class Solution {
//  public:
//   int romanToInt(string s) {
//     int ans = 0;
//     vector<int> roman(128);

//     roman['I'] = 1;
//     roman['V'] = 5;
//     roman['X'] = 10;
//     roman['L'] = 50;
//     roman['C'] = 100;
//     roman['D'] = 500;
//     roman['M'] = 1000;

//     for (int i = 0; i + 1 < s.length(); ++i)
//       if (roman[s[i]] < roman[s[i + 1]])
//         ans -= roman[s[i]];
//       else
//         ans += roman[s[i]];

//     return ans + roman[s.back()];
//   }
// };

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> roman{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int n = s.length();
        int result = roman[s[n - 1]];
        for (int i = n - 2; i >= 0; --i) {
            if (roman[s[i]] < roman[s[i + 1]])
                result -= roman[s[i]];
            else
                result += roman[s[i]];
        }
        return result;
  }
};
