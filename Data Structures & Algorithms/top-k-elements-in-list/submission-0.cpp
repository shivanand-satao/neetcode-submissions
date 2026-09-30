class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;for(int it:nums)mpp[it]++;
        vector<pair<int,int>>arr;for(auto it:mpp)arr.push_back({it.second,it.first});
        sort(arr.rbegin(),arr.rend());
        vector<int>ans;
        for(int i=0;i<k;i++)ans.push_back(arr[i].second);
        return ans;

    }
};
