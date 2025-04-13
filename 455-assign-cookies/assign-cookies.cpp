class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int chi =0;
        int coi =0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(coi <s.size()){
            if(chi<g.size() && g[chi]<=s[coi]){
                chi++;
            }
            coi++;
        }
        return chi;
    }
};