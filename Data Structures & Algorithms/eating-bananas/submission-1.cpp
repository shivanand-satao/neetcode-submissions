class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        int min_k=j;
        while(i<=j){
            int k=i+(j-i)/2;

            int total_h=0;
            for(int it:piles){
                total_h+=ceil(1.0*it/k);
            }
            if(total_h<=h){min_k=k;j=k-1;}
            else i=k+1;
    
        }
        return min_k;
    }
};
