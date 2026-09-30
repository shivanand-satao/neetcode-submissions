class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>mpp(26,0);for(char ch:s)mpp[ch-'a']++;for(char ch:t)mpp[ch-'a']--;for(int it:mpp)if(it)return 0;return 1;
    }
};
