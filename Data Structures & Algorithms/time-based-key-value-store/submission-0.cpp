class TimeMap {
public:
unordered_map<string,vector<pair<string,int>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int i=0;
        int j=mpp[key].size()-1;
        string ans=""; 

        while(i<=j){
            int mid=i+(j-i)/2;
            if(mpp[key][mid].second<=timestamp){
                i=mid+1;
                ans=mpp[key][mid].first;
            }
            else j=mid-1;
        }
        return ans;
    }
};
