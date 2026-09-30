class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int left_max=0;
        int right_max=0;
        int t_water=0;
        while(i<=j){
            
            left_max=max(left_max,height[i]);
            right_max=max(right_max,height[j]);

            if(left_max<=right_max){
                if(height[i]<=left_max && height[i]<=right_max){

                        t_water+=(min(left_max,right_max)-height[i]);

                }
                i++;
            }   
            else if(left_max>right_max){
                if(height[j]<=left_max && height[j]<=right_max){

                        t_water+=(min(left_max,right_max)-height[j]);

                }                
                j--;
            }

        }return t_water;
    }
};
