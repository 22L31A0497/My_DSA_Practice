// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         int count =0;
//         int n = dominoes.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(dominoes[i][0]==dominoes[j][0]&&dominoes[i][1]==dominoes[j][1] ||
//                    dominoes[i][0]==dominoes[j][1]&&dominoes[i][1]==dominoes[j][0]){
//                     count++;
//                    }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int freq[100] = {0}; // Since domino numbers range from 1 to 9, the max key is 9*10 + 9 = 99
        int count = 0;
        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;
            count += freq[key];
            freq[key]++;
        }
        return count;
    }
};