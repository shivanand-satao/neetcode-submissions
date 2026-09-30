class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        int t_water=0;
        int i=0;int max_left=nums[0];
        int j=n-1;int max_right=nums[n-1];
        while(i<j){
            max_left=max(max_left,nums[i]);
            max_right=max(max_right,nums[j]);
            
            if(max_left<=max_right){
                if(max_left>=max_left)t_water+=max_left-nums[i];
                max_left=max(max_left,nums[i]);
                i++;
            }
            else {
                if(max_right>=nums[j])t_water+=max_right-nums[j];
                max_right=max(max_right,nums[j]);
                j--;
            }
        }
        return t_water;
    }
};
