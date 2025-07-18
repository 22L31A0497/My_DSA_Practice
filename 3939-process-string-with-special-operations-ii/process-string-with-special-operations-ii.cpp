
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

// Using long long for k and length is crucial due to the large constraints.
using ll = long long;

class Solution {
public:
    char processStr(string s, ll k) {
        // 'ops' stores pairs of {operation, length_after_operation}.
        std::vector<std::pair<char, ll>> ops;
        ll len = 0;

        for (char c : s) {
            if (isalpha(c)) {
                // For a letter, length increases by 1.
                len++;
                ops.emplace_back(c, len);
            } else if (c == '*') {
                // A '*' operation removes the last character.
                if (len > 0) {
                    len--;
                }
                // We can optimize by merging consecutive '*' ops.
                if (!ops.empty() && ops.back().first == '*') {
                    ops.back().second = len;
                } else {
                    ops.emplace_back('*', len);
                }
            } else if (c == '#') {
                // For '#', length doubles. The buggy length cap is removed.
                if (len > 0) {
                    len *= 2;
                }
                ops.emplace_back('#', len);
            } else { // c == '%'
                // For '%', length is unchanged.
                ops.emplace_back('%', len);
            }
        }

        // If k is out of bounds of the final string, return '.'.
        if (k >= len) {
            return '.';
        }

        // Start the backward pass to find the character.
        return getChar(ops, k);
    }

private:
    char getChar(const std::vector<std::pair<char, ll>>& ops, ll k) {
        // Iterate through the operations in reverse to find the character at index k.
        for (int i = ops.size() - 1; i >= 0; --i) {
            char ch = ops[i].first;
            
            // Get the length *before* this operation. This is more robust.
            ll prev_len = (i > 0) ? ops[i - 1].second : 0;

            if (isalpha(ch)) {
                // Before adding 'ch', length was prev_len. The character 'ch' is at index prev_len.
                if (k == prev_len) {
                    return ch;
                }
            } else if (ch == '#') {
                // Before duplication, length was prev_len.
                // If k is in the duplicated part, map it back to the original part's index.
                if (prev_len > 0 && k >= prev_len) {
                    k -= prev_len;
                }
            } else if (ch == '%') {
                // Before reversing, an index k corresponds to (prev_len - 1 - k).
                k = prev_len - 1 - k;
            }
            // For '*', k remains unchanged because the deletion at the end does not affect an index k < len.
        }
        
        return '.'; // Should not be reached with valid input.
    }
};
