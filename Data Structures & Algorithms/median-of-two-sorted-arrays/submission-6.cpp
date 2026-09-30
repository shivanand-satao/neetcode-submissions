class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();

        int t_len=n1+n2;

        int i=0;
        int j=n1;
        while(i<=j){

            int upper_part=(i+j)/2;

            int lower_part=(t_len+1)/2-upper_part;

            int l1=upper_part==0?INT_MIN:nums1[upper_part-1];
            int l2=lower_part==0?INT_MIN:nums2[lower_part-1];

            int r1=upper_part==n1?INT_MAX:nums1[upper_part];
            int r2=lower_part==n2?INT_MAX:nums2[lower_part];

            if(l1<=r2 && l2<=r1){
                if(t_len%2)return (1.0)*max(l1,l2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2)j=upper_part-1;
            else i=upper_part+1;

        }return 0;
    }
};
