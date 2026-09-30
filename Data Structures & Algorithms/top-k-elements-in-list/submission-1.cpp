class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int,int>mpp;for(int it:nums)mpp[it]++;
        // vector<pair<int,int>>arr;for(auto it:mpp)arr.push_back({it.second,it.first});
        // sort(arr.rbegin(),arr.rend());
        // vector<int>ans;
        // for(int i=0;i<k;i++)ans.push_back(arr[i].second);
        // return ans;
        // tc(n+n+nlogn+k)
        // sc(n+n+k)c

        unordered_map<int,int>mpp;for(int it:nums)mpp[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto it:mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;while(!pq.empty()){ans.push_back(pq.top().second);pq.pop();}return ans;

    }
};
