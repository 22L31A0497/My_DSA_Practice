class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_alt = 0;
        int alt = 0;
        for(int i=0;i<gain.size();i++){
            alt += gain[i];
            max_alt = max(alt,max_alt);
        }
        return max_alt;
    }
};