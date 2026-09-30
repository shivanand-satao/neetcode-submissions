class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string,vector<string>>mpp;
        // for(string s:strs){
        //     string ori=s;
        //     sort(ori.begin(),ori.end());
        //     mpp[ori].push_back(s);
        // }
        // vector<vector<string>>ans;for(auto it:mpp)ans.push_back(it.second);return ans;
        
        unordered_map<string,vector<string>>mpp;
        for(string s:strs){
            vector<int>fq(26,0);for(char ch:s)fq[ch-'a']++;
            string st="";for(int it:fq){st+=to_string(it);st+='#';}
            mpp[st].push_back(s);
        }
        vector<vector<string>>ans;for(auto it:mpp)ans.push_back(it.second);return ans;
        

    }
};
