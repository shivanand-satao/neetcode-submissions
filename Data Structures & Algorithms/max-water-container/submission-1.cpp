class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int max_water=0;
        while(i<j){
            max_water=max(max_water,min(nums[i],nums[j])*(j-i));
            if(nums[i]<=nums[j])i++;else j--;
        }return max_water;
    }
};
