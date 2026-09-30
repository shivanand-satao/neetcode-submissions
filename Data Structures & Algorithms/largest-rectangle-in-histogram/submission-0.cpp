class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //for this que what we will do is go to every index a
        //find the immediate next smaller value index 
        //finsd the immediate previous smaller value index
        // and area for it would be 
        //cuurent height x (next smaller value index - previous smaller value index)
        // find the max area out of all area starting from teh certain index 
        int max_area=0;

        int n=heights.size();
        for(int i=0;i<n;i++){
            int previous_smaller_index=i;
            int next_smaller_index=i;
            
            while(previous_smaller_index>=0 && heights[previous_smaller_index]>=heights[i])previous_smaller_index--;
            
            
            
            while(next_smaller_index<n && heights[next_smaller_index]>=heights[i])next_smaller_index++;
            
            int height_of_rectangle=heights[i];
            int width_of_rectangle=next_smaller_index-1-(previous_smaller_index+1)+1;
            int curr_area=height_of_rectangle*width_of_rectangle;

            cout<<curr_area<<" ";
            max_area=max(max_area,curr_area);

        }
        return max_area;
    }
};
