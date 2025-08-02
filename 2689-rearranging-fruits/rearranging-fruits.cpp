class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
       long long n=basket1.size();

       long long mini=min(*min_element(basket1.begin(),basket1.end()),*min_element(basket2.begin(),basket2.end()));

        map<long long,long long>mpp;
       
        sort(basket1.begin(),basket1.end());
        sort(basket2.begin(),basket2.end());
        for(long long i=0;i<n;i++){
            mpp[basket1[i]]++;
            mpp[basket2[i]]--;
        }
        vector<long long>extra_a;
        vector<long long>extra_b;
        for(auto&p:mpp){
            if(p.second%2!=0)return -1;
           else if(p.second>0){
            for(long long i=0;i<p.second/2;i++){
                extra_a.push_back(p.first);
            }
           }else if(p.second<0){
            for(long long i=0;i<abs(p.second)/2;i++){
                extra_b.push_back(p.first);
            }
           }
        }
        sort(extra_a.begin(),extra_a.end());
        sort(extra_b.rbegin(),extra_b.rend());
        if(extra_a.size()!=extra_b.size())return -1;
        long long total=0;
        
        for(int i=0;i<extra_a.size();i++){
            long long sum1 =min(extra_a[i],extra_b[i]);
            long long sum2 =min(mini,extra_a[i])+min(mini,extra_b[i]);
            total +=min(sum1,sum2);
        }
        return total;
    }
};