class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        list<int> prefix_or;
        unordered_set<int> res;
        for( int num : arr ){
            int cur_or = num;
            auto itr = prefix_or.begin();
            while( itr != prefix_or.end() ){
                if( (*itr | num) != num || *itr == num )
                    break;
                itr = prefix_or.erase(itr);
            }
            if( prefix_or.empty() || *itr != num ){
                itr = prefix_or.insert(itr, num);
                res.insert(num);
            }
            ++itr;
            while( itr != prefix_or.end() ){
                int update = (*itr) | cur_or;
                if( update == *itr )
                    break;
                if( update == cur_or ){
                    itr = prefix_or.erase(itr);
                    continue;
                }
                cur_or = *itr = update;
                res.insert(update);
                ++itr;
            }
        }
        return res.size();
    }
};