class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i!=0 && nums[i-1]==nums[i])continue;
        
        int j=i+1;
        int k=n-1;

        while(j<k){
            int t_sum=nums[i]+nums[j]+nums[k];
            if(t_sum==0){
                res.push_back({nums[i],nums[j],nums[k]});
                while(j<k && nums[j]==nums[j+1])j++;
                while(j<k && nums[k-1]==nums[k])k--;
                j++;
                k--;
            }
            else if(t_sum<0){
                j++;
            }
            else if(t_sum>0){
                k--;
            }
        }
    }
    return res;
    }
};
