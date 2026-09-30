class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
// vector<pair<int,int>>pp;for(int i=0;i<nums.size();i++)pp.push_back({nums[i],i});sort(pp.begin(),pp.end());
// vector<int>ans;
// int i=0,j=nums.size()-1;while(i<j)if(pp[i].first+pp[j].first==target){ans.push_back(pp[i].second);ans.push_back(pp[j].second);break;}else if(pp[i].first+pp[j].first<target)i++;else j--;
// sort(ans.begin(),ans.end());return ans;

vector<int>ans;
unordered_map<int,int>mpp;
for(int i=0;i<nums.size();i++){
    if(mpp.find(target-nums[i])!=mpp.end()){
        ans.push_back(mpp[target-nums[i]]);
        if(ans[0]<i)ans.push_back(i);
        else nums.insert(nums.begin(),i);
        return ans;
    }
    mpp[nums[i]]=i;

}
return {};




    }
};
