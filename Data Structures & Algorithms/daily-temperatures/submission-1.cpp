class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res(n,0);
        stack<int>stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && temperatures[i]>=temperatures[stk.top()])stk.pop();
            if(!stk.empty())res[i]=stk.top()-i;else res[i]=0;
            stk.push(i);
        }
        return res;
    }
};
