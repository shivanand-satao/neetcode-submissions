class Solution {
public:
vector<vector<int>>res;
vector<int>temp;
void rec(int i,vector<int>& nums){
    if(i==nums.size()){
        res.push_back(temp);
        return ;
    }
    temp.push_back(nums[i]);
    rec(i+1,nums);
    temp.pop_back();
    rec(i+1,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        rec(0,nums);
        return res;
    }
};
