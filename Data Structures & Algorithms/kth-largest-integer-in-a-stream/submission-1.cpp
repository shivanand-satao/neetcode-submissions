class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>pq;
int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int it:nums){
            if(pq.size()<k)pq.push(it);
            else if(pq.top()<it){
                pq.pop();
                pq.push(it);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<size)pq.push(val);
        else if(pq.top()<val){
                pq.pop();
                pq.push(val);
            }
        return pq.top();
        
    }

};
