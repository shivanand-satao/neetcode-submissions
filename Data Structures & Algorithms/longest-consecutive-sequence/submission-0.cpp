class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len=0;
        set<int>s(nums.begin(),nums.end());
        vector<int>arr(s.begin(),s.end());
        for(int it:arr)cout<<it<<" ";
        int i=0;
        int j=0;
        while(i<arr.size() && j<arr.size()){
            int add=0;
            while(j<arr.size() && arr[j]==(add+arr[i])){max_len=max(max_len,j-i+1);j++;add++;}
            i=j;
        } 
        return max_len; 
    }
};
