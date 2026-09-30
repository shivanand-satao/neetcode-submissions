class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto& it:points)it.push_back(it[0]*it[0]+it[1]*it[1]);
        auto cmp=[](vector<int>& a,vector<int>& b){
            return a[2]<=b[2];
        };
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<k;i++)points[i].pop_back();
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};
