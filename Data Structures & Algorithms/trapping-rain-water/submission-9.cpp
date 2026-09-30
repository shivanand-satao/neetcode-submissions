class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        
        int i=0;
        int j=n-1;

        int l_max=nums[0];
        int r_max=nums[n-1];

        int t_water=0;

        while(i<=j){
            
            l_max=max(l_max,nums[i]);
            r_max=max(r_max,nums[j]);

            if(l_max<=r_max){
                t_water+=min(l_max,r_max)-nums[i];
                i++;
            }
            else {
                t_water+=min(l_max,r_max)-nums[j];
                j--;
            }
        }
        return t_water;
    }
};
