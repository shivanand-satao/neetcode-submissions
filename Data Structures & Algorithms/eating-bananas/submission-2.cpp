class Solution {
public:
bool is_possible(int cap,vector<int>& piles,int h){
    int cnt=0;
    for(int it:piles){cnt+=it/cap;cnt+=((it%cap)!=0);}
    return cnt<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        int min_h=piles.size();
        while(i<=j){
            int mid=i+(j-i)/2;
            if(is_possible(mid,piles,h)){
                min_h=mid;
                j=mid-1;
            }
            else i=mid+1;
        }return min_h;
    }
};
