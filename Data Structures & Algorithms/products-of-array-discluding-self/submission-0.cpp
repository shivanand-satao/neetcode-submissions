class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool all_zero=false;int pd=1,cnt_of_zero=0;for(int it:nums)if(it==0){if(cnt_of_zero)all_zero=true;else cnt_of_zero++;}else pd*=it;
        vector<int>ans(nums.size(),0);
        if(all_zero)return ans;
        if(cnt_of_zero)for(int i=0;i<nums.size();i++)if(nums[i]==0){ans[i]=pd;return ans;}
        for(int i=0;i<nums.size();i++)ans[i]=pd/nums[i];return ans;
    }
};
