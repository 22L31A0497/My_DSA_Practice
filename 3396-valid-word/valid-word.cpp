class Solution {
public:
    bool isValid(string word) {
       bool consonant=false;
       bool vowel = false;
       if(word.length()<3)return false;
       for(int i=0;i<word.length();i++){
        if(word[i]=='@'||word[i]=='#'|| word[i]=='$'){
            return false;
        }
        word[i]=tolower(word[i]);
        if(word[i]>='a' && word[i]<='z'){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
                vowel = true;
            }else{
                consonant=true;
            }
        }
       }
       return vowel && consonant;
    }
};