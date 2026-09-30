class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int water=0;
        int max_left=0;
        int max_right=0;
        while(i<j){
            max_left=max(max_left,height[i]);
            max_right=max(max_right,height[j]);
            if(max_left<=max_right){
                if(max_left>=height[i])water+=max_left-height[i];
                i++;
            }
            else {
                if(max_right>=height[j])water+=max_right-height[j];
                j--;
            }
        }
        return water;
    }
};
