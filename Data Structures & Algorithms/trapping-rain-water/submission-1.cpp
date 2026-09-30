class Solution {
public:
    int trap(vector<int>& height) {
        int max_water=0;
        int l=0;
        int max_right=0;
        vector<int>max_from_right(height.size(),0);
        for(int i=height.size()-1;i>=0;i--){
            max_right=max(max_right,height[i]);
            max_from_right[i]=max_right;
        }
        for(int it:max_from_right)cout<<it<<"   ";cout<<"\n";
        int max_left=0;
        for(int i=0;i<height.size();i++){
            max_left=max(max_left,height[i]);
            max_water+=(min(max_from_right[i],max_left)-height[i]);
        }
        return max_water;
    }
};
