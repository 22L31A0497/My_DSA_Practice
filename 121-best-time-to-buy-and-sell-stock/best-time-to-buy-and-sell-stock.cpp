class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bb=prices[0];
        int maxip=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<bb){
                bb=prices[i];
            }
            maxip=max(maxip,prices[i]-bb);
        }
        return maxip;
    }
};