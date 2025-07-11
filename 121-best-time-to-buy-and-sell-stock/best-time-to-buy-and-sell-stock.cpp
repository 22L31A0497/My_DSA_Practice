class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first = prices[0];
        int profit = 0;
        for(auto i:prices){
            if(i<first) first = i;
            else profit = max(profit,i-first);
        }
        return profit;
    }
    
    //  int maxProfit(vector<int>& prices) {
    //     int bb=prices[0];
    //     int mp=0;
    //     for(int i=1;i<prices.size();i++){
    //         if(prices[i]<bb){
    //             bb=prices[i];
                
    //         }
    //         mp=max(mp,prices[i]-bb);
    //     } 
    //     return mp;
    // }
};