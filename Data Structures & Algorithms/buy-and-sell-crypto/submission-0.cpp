class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int max_pf=0;

        int n=nums.size();

        int min_till_now=INT_MAX;
        for(int i=0;i<n;i++){
            min_till_now=min(min_till_now,nums[i]);
            max_pf=max(max_pf,nums[i]-min_till_now);
        }
        return max_pf;
    }
};
