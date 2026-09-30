class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(int it:stones)pq.push(it);
        while(pq.size()>1){
            int t1=pq.top();pq.pop();
            int t2=pq.top();pq.pop();
            int add=abs(t1-t2);
            if(add)pq.push(add);;
        }
        if(pq.empty())return 0;return pq.top();
    }
};
