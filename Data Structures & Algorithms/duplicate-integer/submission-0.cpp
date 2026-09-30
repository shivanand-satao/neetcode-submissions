class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;for(int it:nums)if(mpp[it])return 1;else mpp[it]++;return 0;
    }
};