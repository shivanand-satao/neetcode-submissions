class Solution {
public:
    int findMin(vector<int> &nums) {
        int i=0;
        int j=nums.size()-1;
        int min_ele=INT_MAX;
        while(i<=j){    
            int mid=i+(j-i)/2;
            if(nums[i]<=nums[mid]){
                min_ele=min(min_ele,nums[i]);
                i=mid+1;
            }
            else if(nums[mid]<=nums[j]){
                min_ele=min(min_ele,nums[mid]);
                j=mid-1;
            }


        }return min_ele;
    }
};
