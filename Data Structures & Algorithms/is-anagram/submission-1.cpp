class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());sort(t.begin(),t.end());return s==t;
        //vector<int>mpp(26,0);for(char ch:s)mpp[ch-'a']++;for(char ch:t)mpp[ch-'a']--;for(int it:mpp)if(it)return 0;return 1;
    }
};
