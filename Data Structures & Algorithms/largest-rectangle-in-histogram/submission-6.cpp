class Solution {
public:
int get_psi(int i,vector<int>& psi){
    return psi[i];
}
int get_nsi(int i,vector<int>& nsi){
    return nsi[i];
}
    int largestRectangleArea(vector<int>& nums) {
        int max_area=0;
        int n=nums.size();

        vector<int>psi(n,-1);
        vector<int>nsi(n,n);

        stack<int>stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && nums[i]<=nums[stk.top()])stk.pop();
            if(!stk.empty())psi[i]=stk.top();
            stk.push(i);
        }
        while(!stk.empty())stk.pop();
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && nums[i]<nums[stk.top()])stk.pop();
            if(!stk.empty())nsi[i]=stk.top();
            stk.push(i);
        }

        for(int i=0;i<n;i++){
            int psii=get_psi(i,psi);
            int nsii=get_nsi(i,nsi);
            max_area=max(max_area,nums[i]*(nsii-psii-1));
        }
        return max_area;
    }
};
