class Solution {
public:
vector<vector<string>>res;
vector<string>temp;
bool is_pali(string s){
    for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-1-i])return 0;return 1;
}
void rec(string s,int idx){
    if(idx==s.length()){
        res.push_back(temp);
        return ;
    }
    for(int i=idx;i<s.length();i++){
        if(is_pali(s.substr(idx,i-idx+1))){
            temp.push_back(s.substr(idx,i-idx+1));
            rec(s,i+1);
            temp.pop_back();}
    }
}
    vector<vector<string>> partition(string s) {
    rec(s,0);
    return res;    
    }
};
