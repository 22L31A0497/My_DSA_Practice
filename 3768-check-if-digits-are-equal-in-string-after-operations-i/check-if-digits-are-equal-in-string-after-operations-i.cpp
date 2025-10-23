class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() != 2) {
            string s1 = "";
            for (int i = 1; i < s.size(); i++) {
                int x = ((s[i] - 'a') + (s[i - 1] - 'a')) % 10;
                s1 += (x + 'a');
            }
            s = s1;
        }
        return s[0] == s[1];
    }
};