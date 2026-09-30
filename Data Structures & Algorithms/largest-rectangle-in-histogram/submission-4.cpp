class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        int max_area=0;
        stack<int>pse,nse;
        vector<int>pp(n),nn(n);
        for(int i=0;i<n;i++){
            while(!pse.empty() && nums[i]<=nums[pse.top()])pse.pop();
            if(pse.empty())pp[i]=-1;
            else pp[i]=pse.top();
            pse.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!nse.empty() && nums[i]<=nums[nse.top()])nse.pop();
            if(nse.empty())nn[i]=n;
            else nn[i]=nse.top();
            nse.push(i);
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]*(nn[i]-pp[i]+1) <<" ";
            max_area=max(max_area,nums[i]*((nn[i]-1)-(pp[i]+1)+1));}
        
        return max_area;
        
    }
};
