class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int n=mpp[key].size();
        if(n==0)return "";
        int lb=n;
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mpp[key][mid].first>=timestamp){
                j=mid-1;
                lb=mid;
            }
            else i=mid+1;
        }
        if(lb==n)return mpp[key][lb-1].second;
        
        if(mpp[key][lb].first==timestamp){
            return mpp[key][lb].second;
        }
        else if(mpp[key][lb].first>timestamp){
            if(lb==0)return "";
            else return mpp[key][lb-1].second;
        }
        return "";
    }
};
