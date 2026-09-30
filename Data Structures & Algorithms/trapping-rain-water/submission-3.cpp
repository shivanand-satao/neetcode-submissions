class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,0);left[n-1]=nums[n-1];for(int i=n-2;i>=0;i--)left[i]=max(left[i+1],nums[i]);
        vector<int>right(n,0);right[0]=nums[0];for(int i=1;i<n;i++)right[i]=max(right[i-1],nums[i]);
        int t_water=0;
        for(int i=0;i<n;i++)t_water+=(min(left[i],right[i])-nums[i]);
        return t_water;
    }
};
