class Solution {
public:
    int numRabbits(vector<int>& a) {
    //    set<int>st(a.begin(),a.end());
    //    int ans=0;
    //    for(auto it:st){
    //     ans+=it+1;
    //    } 
    //    return ans;
    int ans=0;
    unordered_map<int,int>mpp;
    for(auto it:a){
        mpp[it]++;
        
    }
    for(auto it:mpp){
        int size=it.first+1;
        int grp = it.second/size;
        if(it.second % size) grp++;
        ans += grp*size;
    }
    return ans;
    }
};