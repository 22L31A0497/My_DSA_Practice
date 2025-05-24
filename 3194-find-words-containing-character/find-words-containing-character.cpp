class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;

        // Go through each word in the list
        for (int i = 0; i < words.size(); i++) {
            // Go through each character in the word
            for (char c : words[i]) {
                if (c == x) {
                    result.push_back(i); // Add the index if character x is found
                    break; // No need to check further in this word
                }
            }
        }

        return result;
    }
};
