class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();if(n1>n2)return 0;
        vector<int>mpp1(26,0),mpp2(26,0);
        for(int i=0;i<n1;i++){mpp1[s1[i]-'a']++;mpp2[s2[i]-'a']++;}if(mpp1==mpp2)return 1;
        for(int i=n1;i<n2;i++){
            mpp2[s2[i]-'a']++;
            mpp2[s2[i-n1]-'a']--;
            if(mpp1==mpp2)return 1;
        }
        return 0;
    }
};
