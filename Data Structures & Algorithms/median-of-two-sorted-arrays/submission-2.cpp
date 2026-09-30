class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int n1=nums1.size();   
     int n2=nums2.size();
     
     int i=-1;
     int j=-1;

     int count=0;
     
     int prev=0;
     int curr=0;

     while(count<=(n1+n2)/2){

        prev=curr;
        int upper_next_ele=INT_MAX;
        int lower_next_ele=INT_MAX;
        
        if(i+1<n1)upper_next_ele=nums1[i+1];
        if(j+1<n2)lower_next_ele=nums2[j+1];

        if(upper_next_ele<=lower_next_ele){
            i++;
            curr=nums1[i];
        }
        else {
            j++;
            curr=nums2[j];
        }
        count++;

     }  
    if((n1+n2)%2)return curr;
    return (prev+curr)/2.0;
    }
};
