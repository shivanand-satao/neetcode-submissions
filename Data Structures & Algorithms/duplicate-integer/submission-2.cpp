class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //unordered_map<int,int>mpp;for(int it:nums)if(mpp[it])return 1;else mpp[it]++;return 0;
        //return nums.size()>unordered_set<int>(nums.begin(),nums.end()).size();
        sort(nums.begin(),nums.end());for(int i=1;i<nums.size();i++)if(nums[i]==nums[i-1])return 1;return 0;
    }
};