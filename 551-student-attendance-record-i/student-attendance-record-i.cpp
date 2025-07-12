class Solution {
public:
    // bool checkRecord(string s) {
    //     int ac= 0;
    //     int lc=0;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='A'){
    //            ac++;
    //            if(ac>=2) return false;
    //         }
    //         if(s[i]=='L'){
    //            if(i!=0){
    //              if(s[i]-1 =='L'){
    //                 lc++;
    //                 if(lc>=3) return false;
    //              }
    //            }
    //             else{
    //                 lc=0;
    //             }
    //             lc++;  
    //             if(lc>=3 || ac>=2)return false;  
    //         }
    //     }
    //     return (lc<3 && ac<2);  
    // }
    bool checkRecord(string s) {
    int ac = 0; // absent count
    int lc = 0; // late count (consecutive)

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'A') {
            ac++;
            if(ac >= 2) return false;
            lc = 0; // reset late count on other character
        } else if(s[i] == 'L') {
            lc++;
            if(lc >= 3) return false;
        } else {
            lc = 0; // reset late count on other character
        }
    }

    return true;
}

};