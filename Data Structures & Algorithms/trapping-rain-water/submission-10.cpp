class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int max_left=nums[i];
        int max_right=nums[j];

        int t_water=0;
        while(i<=j){
            max_left=max(max_left,nums[i]);
            max_right=max(max_right,nums[j]);
            if(nums[i]<=nums[j]){
                if(nums[i]<max_left && nums[i]<max_right)t_water+=(min(max_left,max_right)-nums[i]);
                i++;
            }
            else if(nums[i]>nums[j]){
                if(nums[j]<max_left && nums[j]<max_right)t_water+=(min(max_left,max_right)-nums[j]);
                j--;
            }
        }
        return t_water;

    }
};
